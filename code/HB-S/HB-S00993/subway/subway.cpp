#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int c,n,m,d,q;
int tg[M];
int l[2][505][1005];
int l1[3][M];
int t1[M][3];
int mint;
int fi=1;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>tg[i];
    }
    if(c==20||c==21){
        int k;
        for(int i=1;i<=n;i++){
            cin>>k;
            for(int j=1;j<=k;j++){
                int yu;
                cin>>yu;
                cin>>t1[yu][i];
                l1[i][yu]=1;
            }
        }
        for(int i=1;i<=m;i++){
            if(l1[1][i]&&l1[2][i]){
                if(k){
                    mint=t1[i][1]+t1[i][2];
                    k=0;
                }
                else mint=min(mint,t1[i][1]+t1[i][2]);
            }
        }
        while(q--){
            int s,e;
            cin>>s>>e;
            if(n==1){
                cout<<tg[s]+tg[e]<<endl;
            }
            else{
                if((l1[1][s]&&l1[1][e])||(l1[2][s]&&l1[2][e])){
                    cout<<tg[s]+tg[e]<<endl;
                }
                else cout<<tg[s]+tg[e]+mint<<endl;
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>l[0][i][j]>>l[1][i][j];
            }
        }
        while(q--){
            int s,e;
            cin>>s>>e;
            cout<<tg[s]+tg[e]<<endl;
        }
    }
    return 0;
}
