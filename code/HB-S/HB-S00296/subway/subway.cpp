#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N],k[N];
struct nod{
    int a;
    int t;
}s[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>s[i].a>>s[i].t;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=w[x]+s[x].t+s[x].t+w[y];
        cout<<ans<<endl;
    }
}
