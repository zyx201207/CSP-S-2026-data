#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int n;
ll d,x[N],sum[N];
map<ll,int>stpl,cnt;
void dfs(ll dis,ll stp,int id){//当前 
	if(!stpl.count(dis)){//第一次到达 
		stpl[dis]=stp;
		cnt[dis]=1;
	}else if(stpl[dis]>stp){//比 
		stpl[dis]=stp;
		cnt[dis]=1;
	}else if(stpl[dis]==stp)cnt[dis]++;
	for(int i=id+1;i<=n&&abs(x[i]-x[id])<=d;i++){
		dfs(dis+abs(x[i]-x[id]),stp+1,i);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=2;i<N;i++)sum[i]=sum[i-1]+(sum[i-1]-sum[i-2])+1;
	while(t--){
		cnt.clear();
		stpl.clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		dfs(0,0,1);
//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll tmp=cnt[x[i]];
			if(tmp>1){
				ans+=sum[tmp];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
