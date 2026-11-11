#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500010],t[1010][1010],t1,sum[500010],x,y,s[500010];
vector<ll>a[500010],b[500010];
bool vis[500010];
bool is_b;
void dfs(ll k){
	if(k==y){
		return ;
	}
	for(auto p:b[k]){
		for(auto l:a[p]){
			if(vis[l]==0){
				sum[l]=min(sum[l],sum[k]+t[k][p]+t[l][p]);
				vis[l]=1;
				dfs(l);
				vis[l]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(sum,0x3f,sizeof(sum));
	cin>>c>>n>>m>>d>>q;
	if(c>=12&&c<=19){
		is_b=1;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a[i].push_back(x);
			b[x].push_back(i);
			t[x][i]=y;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		sum[x]=w[x];
		vis[x]=1;
		dfs(x);
		cout<<sum[y]+w[y]<<endl;
	}
	return 0;
}
