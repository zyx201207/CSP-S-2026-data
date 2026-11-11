#include<bits/stdc++.h>
using namespace std;
const long long M=500010,N=520;
long long c,n,m,d,q,w[M],k[N],ans,val,val2,a1[510][1010],t1[510][1010],a[499][19999],t[499][19999],x,y,lt[1010][1010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c<=11){
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>a1[i][j]>>t1[i][j];
                if(j>1){
                    lt[a1[i][j]][a1[i][j-1]]=t1[i][j]+t1[i][j-1];
                    val+=lt[a1[i][j]][a1[i][j-1]];
                }
            }
        }
        for(int i=1;i<=q;i++){
            cin>>x>>y;
            ans=w[x]+w[y];
            if(lt[x][y]){
                ans+=lt[x][y];
                cout<<ans<<"\n";
            }else{
                ans+=val;
                cout<<ans<<"\n";
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>a[i][j]>>t[i][j];
                if(j>1){
                    lt[a[i][j]][a[i][j-1]]=t[i][j]+t[i][j-1];
                    val2+=lt[a[i][j]][a[i][j-1]];
                }
            }
        }
        for(int i=1;i<=q;i++){
            cin>>x>>y;
            ans=w[x]+w[y];
            if(lt[x][y]){
                ans+=lt[x][y];
                cout<<ans<<"\n";
            }else{
                ans+=val2;
                cout<<ans<<"\n";
            }
        }
    }
}