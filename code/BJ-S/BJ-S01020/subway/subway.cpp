#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=1e5+10;
ll c,n,m,d,q,w[N],k[500],a[100][N],t[100][N],x[M],y[M],sum;//0 ≤ c ≤ 25,1 ≤ n ≤ 500,1 ≤ m ≤ k≤ 5e5 ,1 ≤ d ≤ 20,1 ≤ q ≤ 1e5 ;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            sum+=t[i][j];
        }
    }
    for(ll i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        cout<<x[i]+y[i]<<endl;
    }
   
    return 0;
}
