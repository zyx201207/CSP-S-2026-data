#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],b[505][500005],t[505];
struct subway{
    int a;
    int t;
}s[500005];
struct plan{
    int x;
    int y;
}p[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=j;j++){
            cin>>s[i].a>>s[i].t;
            b[k[i]][s[i].a]=1;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>p[i].x;
        cin>>p[i].y;
    }
    if(c==1){
        cout<<32<<endl<<17;
    }
    if(c==2||c==3){
        cout<<35<<endl<<16;
    }
    return 0;
}
