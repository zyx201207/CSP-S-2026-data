#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l,llst,rlst,r,ans;
pair<char,int> f[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;r=n+1;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        f[i].first=c;
        f[i].second=a;
    }
    while(l<r){
      while(llst<=rlst&&l<r){
            llst+=f[++l].second;
            if(f[l].first!=f[r].first){
                if(llst<=rlst) ans+=f[l].second;
                else ans+=rlst-llst+f[l].second;
            }
        }
       while(rlst<=llst&&l<r){
            rlst+=f[--r].second;
            if(f[l].first!=f[r].first){
                if(rlst<=llst) ans+=f[r].second;
                else ans+=llst-rlst+f[r].second;
            }
        }
    }
    cout<<ans;
    return 0;
}
