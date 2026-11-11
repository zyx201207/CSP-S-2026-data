#include <bits/stdc++.h>

using namespace std;
long long c,n,m,d,q;
long long a[500005];
int d[505];
int bfs(int y,int w){
    bool t=false;
    while(t==true){
        for(int i=0;i<d[w];i++){
            b[w][i].ai
        }
    }
}
struct q{
    int ai;
    int ti;
};
q b[1000005][1000005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int ant=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        d[ant++]=x;
        for(int j=0;j<x;j++){
            cin>>b[i][j].ai>>b[i][j].ti;
        }
    }
    for(int i=0;i<n;i++){
        bfs(b[i][0].ai,i);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
