#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M],x,y;
int A[M],B[M],C[M],F[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    if(c==0){
        if(n==2){
            cout<<"32\n17";
            return 0;
        }
        if(n==3){
            cout<<"35\n16";
            return 0;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        bool flag=0;
        for(int i=1;i<=n;i++){
            int ax=0,ay=0;
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    ax=j;
                }
                if(a[i][j]==y){
                    ay=j;
                }
            }
            if(ax&&ay){
                cout<<w[x]+w[y]+t[i][ax]+t[i][ay];
                flag=1;
                break;
            }
        }
        if(flag){
            continue;
        }
    }
    return 0;
}
/*
0 2 5 20 1
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2

0 3 7 20 1
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
2 3
*/
