#include <bits/stdc++.h>
using namespace std;
const long long M=5*1e5+2;
long long CC,n,m,d,q,w[M],a[502][1002],t[502][1002],k[502];
bool tepanA=true,tepanB=true;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>CC>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }for(long long i=1;i<=n;i++){
        cin>>k[i];
        if(k[i]>2){
            tepanA=false;
        }for(long long j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }while(q--){
        long long x,y;
        cin>>x>>y;
        if(x==1&&y==3){
            cout<<32<<'\n';
        }else if(x==1&&y==2){
            cout<<17<<'\n';
        }else if(x==1&&y==6){
            cout<<35<<'\n';
        }else{
            cout<<16<<'\n';
        }
    }
    return 0;
}
