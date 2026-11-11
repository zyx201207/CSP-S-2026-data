#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k;
int w[1000005];
int b[100005][100][10],minn = 1e10;
int a[1000005][100],t[1000005][100];
void abc(int bushu,int che,int last){
    if(last == che ) minn = min(minn,bushu);
    for(int i = 1;i<=100;i++){
        for(int j = 1;j<=100;j++){
            for(int z = 1;z<=100;z++){
                abc(bushu+=t[j][i]+w[b[i][j][z]],b[i][j][z],last);
            }
        }

    }
}
int main(){
    freopen("subway","r",stdin);
    freopen("subway","r",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=500;i++){
        for(int j = 1;j<=500;j++){
            for(int z = 1;z<500;z++){
                b[i][j][z]  = 0;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        cin>>k;
        for(int j = 1;j<=2*k;j++){

            cin>>a[j][i]>>t[j][i];
            for(int z = 1;z<j;z++){
                b[a[z][i]][a[j][i]][i] = 1;
                b[a[j][i]][a[z][i]][i] = 1;
            }
        }
    }
    for(int i = 1;i<=q;i++){
        int start,last;
        cin>>start>>last;
        abc(0,start,last);
        cout<<minn;
    }

    return 0;
}
