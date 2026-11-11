#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long sum=0;
long long n,m,ans=1,flag,ji=0;
int a[N]={0},c[N]={0},s[N]={0},t[N]={0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        c[i]=a[i]-a[i-1];
        if(i>2&&c[i]!=c[i-1]){
            ji=1;
        }
    }
    if(ji==0){
        long long xiha=sqrt(2*m/c[2]);
        while(xiha*(xiha+1)/2*c[2]<=m){
            xiha+=1;
        }
        cout<<xiha;
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        flag=-1;
        for(int j=i-1;j>=0;j--){
            s[j]=s[j+1]+c[j+1];
            if(s[j]>m)break;
        }
        for(int j=i-1;j>=0;j--){
            t[j]=t[j+1]+s[j+1];
            if(t[j]>m){
                flag=j;
                break;
            }
        }
        ans=max(ans,i-flag-1);
    }
    cout<<ans;
    return 0;
}
