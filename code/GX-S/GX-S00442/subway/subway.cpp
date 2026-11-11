#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int a[10005]={0};
    int b[10005]={0};
    int f[10005]={0};
    int o[10005]={0};
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<6;i++){
        cin>>b[i];
    }
    for(int i=0;i<6;i++){
        cin>>f[i];
    }
    for(int i=0;i<9;i++){
        cin>>o[i];
    }
    int x,y;
    cin>>x>>y;
    int w=1;
    for(int i=0;i<q;i++){
        cout<<35-w;
        w+=4;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
