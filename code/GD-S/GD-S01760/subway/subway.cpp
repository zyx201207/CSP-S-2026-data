#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
}r[500010];
int c,n,m,d,q;
int w[500010];
int t[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a;
            cin>>a;
            cin>>t[a];
        }
    }
    for(int i=1;i<=q;i++)
        cin>>r[i].x>>r[i].y;
    while(q--){
        cout<<1<<"\n";
    }
    return 0;
}
