#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,d[N];
bool flag,flg;
long long m,ans,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long d=a[2]-a[1];
    for(int i=2;i<n;i++)
        if(a[i+1]-a[i]!=d)
            flag=true;
    if(n<=5000){
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            long long sum=0,cnt=0;
            for(int j=1;j<=i;j++)
                if(sum+(a[i]-a[j])<=m){
                    sum+=(a[i]-a[j]);
                    cnt++;
                }
            ans=max(ans,cnt);
        }
        cout<<ans<<'\n';
        return 0;
    }
    if(!flag){
        for(int i=1;;i++)
            if(1ll*(i+1)*i*abs(d)/2>m){
                cout<<i<<'\n';
                return 0;
            }
    }
    return 0;
}