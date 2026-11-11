#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s[200005],s1[200005];
bool f[200005][35],t[200005],t1[200005];
ll ans;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>s1[i];
        s[i]=s1[i];
        int k=0;
        while(s[i]){
            f[i][++k]=s[i]&1;
            s[i]/=2;
        }
    }
    for(int i=1;i<=n;i++){
        t[i]=1;
    }
    for(int i=35;i>=1;i--){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=f[j][i];
            t1[j]=t[j];
        }
        if(sum>=m){
            for(int j=1;j<=n;j++){
                if(!f[j][i])t1[j]=0;
            }
            int tmp=0;
            for(int j=1;j<=n;j++){
                tmp+=t1[j];
            }
            if(tmp>=m){
                for(int j=1;j<=n;j++){
                    t[j]=t1[j];
                }
            }
        }

    }
    bool flag=1;
    for(ll i=1;i<=n;i++){
        if(t[i]){
            if(flag){
                ans=s1[i];
                flag=0;
            }else{
                ans&=s1[i];
            }
        }

    }
    cout<<ans;
    return 0;
}
