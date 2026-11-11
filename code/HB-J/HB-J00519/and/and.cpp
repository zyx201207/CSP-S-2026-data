#include<bits/stdc++.h>
#define ll long long
using namespace std;
//ten year oi one groud null no open long long meet grandfather
ll x[100005];
ll dp[100005];
bool v[100005];
ll n,m;
void dfs(ll ans,ll mm){
	if(dp[mm]<ans){
		dp[mm]=ans;
		cout<<mm<<' '<<ans<<endl;
	}
	else{
		return;
	}
	if(mm==m+1){
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==1)continue;
		else {v[i]=1;dfs(ans&x[i],mm+1);}
		v[i]=0;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+1+n,cmp);
	for(int i=1;i<=n;i++){
		v[i]=1;
		dfs(x[i],2);
		v[i]=0;
	}
	cout<<dp[m+1]<<'\n';
	return 0;
}
