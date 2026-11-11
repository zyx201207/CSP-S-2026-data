#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,ans=0,dis=1;
long long a[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        cnt+=(a[i]-a[i-1])*(i-dis);
        if(cnt>m){
            while(cnt>m){
                cnt-=(a[i]-a[dis]);
                dis++;
            }
        }
        ans=max(ans,i-dis+1);
    }
    cout<<ans;
    return 0;
}

