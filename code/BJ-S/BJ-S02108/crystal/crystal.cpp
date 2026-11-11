#include<bits/stdc++.h>
using namespace std;
int a[100010];
bool vis[100010];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,sum=0,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    for(int i=1;i<=n;i++){
        if(sum<a[i]){
            a[i]=0;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        int nn=sum-a[i];
        if(sum-a[i]<=m){
            a[i]=sum;
            m=m-nn;
            ans++;
        }
    }

    cout<<ans;
    return 0;
}
