#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[500010],y,ans=-1,n,bb=0;
vector<pair<ll ,ll > >a[500020];
ll mymin(ll ee ,ll ff){
	if(ee==-1){
		return ff;
	}
	if(ee<ff){
		return ee;
	}
	return ff;
}
void dfs(int m,ll sum ,int f){
	if(f!=0){
	
	sum+=a[f][m].second;
	if(m==y){
		ans=mymin(ans,sum);
		return ;
	}
	}
	for(int i=1;i<=n;i++){
		int fla=0;
		for(int j=0;j<a[i].size();j++){
			if(a[n][j].first==m){
				fla=1;
				break;
			}
		}
		if(fla==1){
			for(int j=0;j<a[i].size();j++){
				if(j!=m){
					if(bb==0){
						sum+=a[i][m].second;
						bb=1;
					}
				dfs(a[i][j].first,sum+a[i][m].second,i);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,m,d,q,k,e,e1,t,x;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		
		for(int j=1;j<=k;j++){
			cin>>e>>t;
			a[i].push_back({e,t});
		}
	}
	while(q--){
		cin>>x>>y;
		ans=-1;
		dfs(x,0,0);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
