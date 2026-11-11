#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,t,n[100001],d[100001],x[100001][100001];
    for(int forr=0;forr<t;forr++){
        int fx[100000][100000][100000];
        cin>>n[forr]>>d[forr];
        for(int i=0;i<=n[forr];i++){
            cin>>x[forr][i];
        }
        for(int i=0;i<=n[forr]-1;i++){
            for(int j=0;j<=n[forr]-1;j++){
                fx[forr][i][j]=x[forr][i+j]-x[forr][i];
            }
            sort(fx[forr][i][0],fx[forr][i][n-1]);
        }
        

    }
    return 0;
}

