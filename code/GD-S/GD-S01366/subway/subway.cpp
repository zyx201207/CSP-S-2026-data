#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sta{
	int u,v;//存边 
};
ll c;
ll n,m,d,q;
// Line数 地铁站数 站最大换乘线数 plan数 
ll w[500010];
ll k[508];
ll a[508][10010],t[508][10010];//10010开多MLE只是pf 
ll x[100010],y[100010];
vector<sta> ln[500010];//存边 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//c=0就是样例
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++){//只能算出发到达都在Line1的结果 
		int r,e;
		for(int j=1;j<=k[1];j++){
			if(a[1][j]==x[i]) r=j;	
		}
		for(int j=1;j<=k[1];j++){
			if(a[1][j]==y[i]) e=j;
		}
		ll tm=w[x[i]]+t[1][r]+t[1][e]+w[y[i]];
		cout<<tm<<endl;
	}
	return 0;
}
