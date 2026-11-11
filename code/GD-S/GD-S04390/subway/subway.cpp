#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct mm{
	ll a,t;
};
mm ca[50005][50005];
ll c,n,m,d,q,w[500005],v[50005],s=50005;

void dfs(ll x,ll y,ll ans){
	if(x==y){
		s=min(s,ans);
		return ;
	}
	for(int i = 1; i <= n ; i ++){
		for(int j = 1 ; j <= ca[i][0].a ; j ++){
			if(ca[i][j].a==x&&v[ca[i][j].a]!=1){
				v[ca[i][j].a]=1;
				dfs(ca[i][j].a,y,ans+ca[i][j].t);
				v[ca[i][j].a]=0;
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	for(ll i = 1; i <= m ; i ++){
		cin>>w[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		ll z;
		cin>>z;
		ca[i][0].a=z;
		for(ll j = 1 ; j <= z ; j ++){
			cin>>ca[i][j].a>>ca[i][j].t;		
		}
	}
	while(q--){
		ll x,y,ans=0;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		dfs(x,y,ans);
		cout<<s<<endl;
	}
	
	
}
