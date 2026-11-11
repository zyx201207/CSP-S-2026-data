#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(long long a,long long b){return a>b;}
long long a[500001],d[500001],r[500001],s[500002],m,mx;
int vis[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,cmp);
    vis[n]=1;
    r[n]=m,s[n]=a[n];
    mx=1;
    for(int i=n-1;i>0;i--){
        s[i]=s[i]+s[i+1];
        if(r[i+1]>=vis[i+1]*(a[i]-a[i+1])){
            r[i]=r[i+1]-vis[i+1]*(a[i]-a[i+1]);
            vis[i]=vis[i+1]+1;
        }
        else{
            if(m<a[i]-a[i+1]){
                vis[i]=1;
                r[i]=m;
                goto com;
            }
            int j=1;
            while(r[i+1]<(vis[i+1]-j)*(a[i]-a[i+1]))j++;
            vis[i]=vis[i+1]-j+1;
            int k=i+vis[i+1]-j;
            r[i]=r[i+1]+s[k]-s[k+j+1]-(vis[i+1]-j)*(a[i]-a[i+1]);

        }
        com:
        mx=max(mx,(long long)(vis[i]));
    }
    cout<<mx;
    return 0;
}
