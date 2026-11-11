#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll w[500010];
ll k[510];
ll a[510][100010];
ll t[510][100010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(c>3){
        return 0;
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll he=0;
        he+=w[x]+w[y];
        for(int i=1;i<=n;i++){
            bool f1=0,f2=0;
            ll sum=0;
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    f1=1;
                    sum+=t[i][j];
                }
                if(a[i][j]==y){
                    f2=1;
                    sum+=t[i][j];
                }
            }
            if(f1&&f2){
                cout<<sum<<endl;
            }
        }
    }
	return 0;
}
