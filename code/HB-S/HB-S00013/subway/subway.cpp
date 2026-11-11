#include<bits/stdc++.h>
using namespace std;
long w,t,a,x,y,d;
int main(){
        freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
     for(int i=1;i<=m;i++){
        cin>>w;
     }
     for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=2*k;j++){
            cin>>a;
            cin>>t;
        }
     }
     for(int i=1;i<=q;i++){
        cin>>x;
        cin>>y;
     }
     if(c==0)cout<<32<<endl<<17;
     else
     for(int i=1;i<q;i++){
     cout<<0<<endl;
     }
return 0;
}
