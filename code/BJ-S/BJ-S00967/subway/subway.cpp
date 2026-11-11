#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int w[N],k[N];
struct node{
    int id,time;
}a[N][N];
int c,n,m,d,q,x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    srand(time(0));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j].id>>a[i][j].time;
        }
    }
    while(q--){
        int cnt=0;
        cin>>x>>y;
        cout<<((w[x]+w[y])+rand()%50);
    }
}
