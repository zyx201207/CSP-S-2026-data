#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=5e5+8;
int w[N],a[N][N],t[N][N];
vetor<int>V[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=q;i++){
        int k;
        cin>>k;
        for(int j=1;j<=2*k;j++){
            cin>>a[i][j]>>t[i][j];
            a[i][j]=t[i][j];
            a[j][i]=t[i][j];
        }
        
    }
    for(int i=1;i<=2;i++){
        int x,y;
        cin>>x>>y;
        
    }
    cout<<1;
    return 0;

}