#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long a[N],m,ans=1,s[N],n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++)
        s[i]=a[i]+s[i-1];
    if(n<=5000){
        for(long long i=1;i<n;i++)
            for(long long j=i+1;j<=n;j++)
                if((s[j]-s[i-1]+m)/(j-i+1)>=a[j]) ans=max(j-i+1,ans);
        cout<<ans<<endl;
        return 0;
    }
    bool fl=0,ag=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            fl=1;
            break;
        }
    }
    for(int i=2;i<n;i++){
        if(a[i+1]-a[i]!=a[i]-a[i-1]){
            ag=1;
            break;
        }
    }
    if(fl==0){
        for(long long i=1;i<n;i++){
            if(s[i]==m){
                cout<<i+1;
                return 0;
            }
            if(s[i]>m){
                cout<<i;
                return 0;
            }
        }
    }
    if(ag==0){
        for(long long i=1;i<n;i++){
            if(s[i]==m){
                cout<<i+1;
                return 0;
            }
            if(s[i]>m){
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}
