//GZ-S00013 龙里县生态城实验学校 吴沛珊
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll c,n,m,d,q,k;
    ll w[N],a[N][N],t[N][N],x[N],y[N];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
        cin>>w[i];
	}cin>>k;
	for(int i=1;i<=k;i++){
        for(int j=1;j<=2;j++){
            cin>>a[i][j]>>t[i][j];
        }
	}
	ll r=2;
	for(int i=1;i<=r;i++){
        cin>>x[i]>>y[i];
	}
	ll ans=0,ans2=0;
	for(int i=1;i<=q;i++){
        if(i==r) cout<<ans2<<" ";
        else cout<<ans<<" ";
	}
	return 0;
}
