#include<bits/stdc++.h>
using namespace std;using LL=long long;
#define f(i,a,b) for(int i=(a),E##i=(b);i<=E##i;++i)
#define fr(i,a,b) for(int i=(a),E##i=(b);i>=E##i;--i)
#define fu(i,a,b) for(int i=(a),E##i=(b);i<E##i;++i)
constexpr LL LINF=2e18;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    if(c<=10){
        while(t--){
            int n;LL d;cin>>n>>d;
            vector<LL>a(n+1);f(i,1,n)cin>>a[i];
            vector<int>nxt(n+1);f(i,1,n){
                nxt[i]=upper_bound(a.begin()+1,a.begin()+n+1,a[i]+d)-a.begin()-1;
            }
            LL ans=0;
            fu(l,1,n){
                int cnt=0;
                int k=nxt[l];
                if(nxt[l]!=l)f(r,l+1,n){
                    if(nxt[l]<r){
                        if(nxt[k]<r){
                            int k2=nxt[k];
                            if(nxt[k-2]==k2){
                                cnt=-1e9;
                            }
                            if(nxt[k-1]==k2){
                                ++cnt;
                            }
                            k=k2;
                        }
                        if(nxt[k-2]<r){
                            if(cnt+(nxt[k-1]>=r)==1){
                                ++ans;
                            }
                        }
                    }
                    if(nxt[r]==r)break;
                }
            }
            cout<<ans<<endl;
        }
    }
    if(c==11||c==12){
        while(t--){
            int n;LL d;cin>>n>>d;
            vector<LL>a(n+1);f(i,1,n)cin>>a[i];
            vector<int>nxt(n+1);f(i,1,n){
                nxt[i]=upper_bound(a.begin()+1,a.begin()+n+1,a[i]+d)-a.begin()-1;
            }
            LL ans=0;
            f(l,1,1){
                int cnt=0;
                int k=nxt[l];
                if(nxt[l]!=l)f(r,l+1,n){
                    if(nxt[l]<r){
                        if(nxt[k]<r){
                            int k2=nxt[k];
                            if(nxt[k-2]==k2){
                                cnt=-1e9;
                            }
                            if(nxt[k-1]==k2){
                                ++cnt;
                            }
                            k=k2;
                        }
                        if(nxt[k-2]<r){
                            if(cnt+(nxt[k-1]>=r)==1){
                                ans+=n-r+1;break;
                            }
                        }
                    }
                    if(nxt[r]==r)break;
                }
            }
            cout<<ans<<endl;
        }
    }
}
//17:49