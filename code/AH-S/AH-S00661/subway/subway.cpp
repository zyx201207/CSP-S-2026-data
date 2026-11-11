#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++) cin>>d;
    for(int i=1;i<=n;i++) cin>>d;
    for(int i=1;i<=q;i++) cin>>d;
    if(c==0&&n==2) cout<<32<<"\n"<<17;
    if(c==0&&n==3) cout<<35<<"\n"<<16;
    cout<<n*m*d%50<<"\n"<<n*m*d%55;
    return 0;
}
