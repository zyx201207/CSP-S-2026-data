#include<bits/stdc++.h>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _rep(i,x,y) for(int i=x;i<y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
using namespace std;
#define int long long
const int N=2000005;
int n,d;
int X[N],ans;
int nxt[N];

void solve(){
    ans=0;
    memset(nxt,0,sizeof nxt);
    cin>>n>>d;
    _for(i,1,n) cin>>X[i];

    _for(i,1,n){
        nxt[i]=max(nxt[i-1],i);
        while(nxt[i]+1<=n&&X[nxt[i]+1]-X[i]<=d){
            nxt[i]++;
        }
    }
    _for(i,1,n){
        int pos=i,KK=0;
        vector<int> path;
        path.push_back(i);
        int yu=0;
        while(1){
            if(n<=5000 || nxt[pos]-pos<=5){
                _for(j,pos+1,nxt[pos]){
                    if(path.size()>=2){
                        int SZ=path.size();
                        int A=X[path[SZ-2]];
                        int B=X[j];
                        int mid=path[SZ-1];
                        int del=yu;
                        //cout<<A<<' '<<B<<' '<<mid<<' '<<yu<<'\n';
                        del+=(mid>=2&&abs(X[mid-1]-A)<=d&&abs(X[mid-1]-B)<=d);
                        //cout<<(mid>=2&&abs(X[mid-1]-A)<=d)<<'\n';
                        del+=(mid>=3&&abs(X[mid-2]-A)<=d&&abs(X[mid-2]-B)<=d);
                        del+=(mid< n&&abs(X[mid+1]-A)<=d&&abs(X[mid+1]-B)<=d);
                        del+=(mid<n-1&&abs(X[mid+2]-A)<=d&&abs(X[mid+2]-B)<=d);
                        if(del==1) ans++;
                    }
                }
            }else{
                if(path.size()>=2){
                    int L=pos+1,R=nxt[pos],res=0,G=pos;
                    while(L<=R){
                        int mid=L+R>>1;
                        int SZ=path.size();
                        int A=X[path[SZ-2]];
                        int B=X[mid];
                        int M=path[SZ-1];
                        int del=yu;
                        //cout<<A<<' '<<B<<' '<<mid<<' '<<yu<<'\n';
                        del+=(M>=2&&abs(X[M-1]-A)<=d&&abs(X[M-1]-B)<=d);
                        //cout<<(mid>=2&&abs(X[mid-1]-A)<=d)<<'\n';
                        del+=(M>=3&&abs(X[M-2]-A)<=d&&abs(X[M-2]-B)<=d);
                        del+=(M< n&&abs(X[M+1]-A)<=d&&abs(X[M+1]-B)<=d);
                        del+=(M<n-1&&abs(X[M+2]-A)<=d&&abs(X[M+2]-B)<=d);
                        if(del>=1){
                            L=mid+1; res=mid;
                        }else R=mid-1;
                    }
                    L=pos+1,R=nxt[pos];
                    while(L<=R){
                        int mid=L+R>>1;
                        int SZ=path.size();
                        int A=X[path[SZ-2]];
                        int B=X[mid];
                        int M=path[SZ-1];
                        int del=yu;
                        //cout<<A<<' '<<B<<' '<<mid<<' '<<yu<<'\n';
                        del+=(M>=2&&abs(X[M-1]-A)<=d&&abs(X[M-1]-B)<=d);
                        //cout<<(mid>=2&&abs(X[mid-1]-A)<=d)<<'\n';
                        del+=(M>=3&&abs(X[M-2]-A)<=d&&abs(X[M-2]-B)<=d);
                        del+=(M< n&&abs(X[M+1]-A)<=d&&abs(X[M+1]-B)<=d);
                        del+=(M<n-1&&abs(X[M+2]-A)<=d&&abs(X[M+2]-B)<=d);
                        if(del>1){
                            L=mid+1;G=mid;
                        }else R=mid-1;
                    }
                    ans+=max(0ll,res-G);
                }
            }
            int Next=nxt[pos];
            if(Next==pos||Next==n){
                KK=1;break;
            }
            pos=Next;
            path.push_back(Next);
            if(path.size()>=3){
                int p=path.size()-3;
                int A=X[path[p]];
                int B=X[path[p+2]];
                int mid=path[p+1];
                yu+=(mid>=2&&abs(X[mid-1]-A)<=d&&abs(X[mid-1]-B)<=d);
                yu+=(mid>=3&&abs(X[mid-2]-A)<=d&&abs(X[mid-2]-B)<=d);
                yu+=(mid< n&&abs(X[mid+1]-A)<=d&&abs(X[mid+1]-B)<=d);
                yu+=(mid<n-1&&abs(X[mid+2]-A)<=d&&abs(X[mid+2]-B)<=d);
            }
            //cout<<pos<<' '<<yu<<' '<<ans<<'\n';
            if(yu>=2) break;
        }
        //cout<<i<<','<<j<<" 's path:\n";
        //for(auto P:path) cout<<P<<' ';
        //cout<<'\n';
        int sz=path.size();
        /*_for(p,0,sz-3){
            int A=X[path[p]];
            int B=X[path[p+2]];
            int mid=path[p+1];
            yu+=(mid>=2&&abs(X[mid-1]-A)<=d&&abs(X[mid-1]-B)<=d);
            yu+=(mid>=3&&abs(X[mid-2]-A)<=d&&abs(X[mid-2]-B)<=d);
            yu+=(mid< n&&abs(X[mid+1]-A)<=d&&abs(X[mid+1]-B)<=d);
            yu+=(mid<n-1&&abs(X[mid+2]-A)<=d&&abs(X[mid+2]-B)<=d);
            if(yu>=2) break;
        }*/
        //if(yu==1)
            //cout<<i<<','<<j<<'\n';
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
