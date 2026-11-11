#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m=1,sum,ans,a[200005],st1[200005],st2[200005];
char c[200005];
vector <int> d;
vector <char> k;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n,d.resize(n+1),k.resize(n+1);
    for(int i=1;i<=n;++i) cin>>a[i]>>c[i];
    d[1]=a[1],k[1]=c[1];
    for(int i=2;i<=n;++i){
        if(c[i]==k[m]) d[m]+=a[i];
        else{
            d[++m]=a[i];
            k[m]=c[i];
        }
    }
    st1[1]=1,st2[m]=1;
    for(int i=2;i<=m;++i) st1[i]=st1[i-1]+d[i];
    for(int i=m-1;i>=1;--i) st2[i]=st2[i+1]+d[i];
    int pl=0,pr=0,l=0,r=m+1,del=0;
    while(l<r&&l!=r-1){
        if(pl==pr){
            // cerr<<"enter pl=pr\n";
            ++l,--r;
            pl+=d[l],pr+=d[r];
            if(k[l]!=k[r]) ans+=min(d[l],d[r]);
            // cerr<<"ans <- "<<ans<<"\n";
            // cerr<<"now pl,pr = "<<pl<<","<<pr<<"\n";
            del+=min(d[l],d[r]);
        }
        while(pr>pl&&l<r){
            // cerr<<"enter pl<pr, now pl,pr = "<<pl<<","<<pr<<"\n";
            pl+=d[++l];
            if(pl>=pr){
                // cerr<<"now pl,pr = "<<pl<<","<<pr<<"\n";
                // cerr<<"pl>=pr!";
                if(k[l]!=k[r]) ans+=d[l]-(pl-pr);
                del+=d[l]-(pl-pr);
                // cerr<<"ans <- "<<ans<<"\n";
            }
            else{
                // cerr<<"now pl,pr = "<<pl<<","<<pr<<"\n";
                // cerr<<"no break\n";
                if(k[l]!=k[r]) ans+=d[l];
                del+=d[l];
            }
        }
        while(pr<pl&&l<r){
            // cerr<<"enter pl>pr, now pl,pr = "<<pl<<","<<pr<<"\n";
            pr+=d[--r];
            if(pr>=pl){
                // cerr<<"now pl,pr = "<<pl<<","<<pr<<"\n";
                // cerr<<"pl<=pr!";
                if(k[r]!=k[l]) ans+=d[r]-(pr-pl);
                del+=d[r]-(pr-pl);
                // cerr<<"ans <- "<<ans<<"\n";
            }
            else{
                // cerr<<"now pl,pr = "<<pl<<","<<pr<<"\n";
                // cerr<<"no break\n";
                if(k[l]!=k[r]) ans+=d[r];
                del+=d[r];
            }
        }
    }
    cout<<ans<<"\n";
    cout.flush();
    return 0;
}
