#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int check(int x){
	int res=0;
	while(x)res+=(x&1),x>>=1;
	return res;
}
int n,m;
ll ans=-1;
ll a[N];
void dfs(ll cnt,int now,int id){
	if(now==m){
		ans=max(ans,cnt);
		return ;
	}
	if(id==n)return ;
	for(int i=id+1;i<=n;i++){
		if(!now)dfs(a[i],now+1,i);
		else dfs(cnt&a[i],now+1,i);
		dfs(cnt,now,i);
	}
}
bool cmp(ll a,ll b){
	return a>b;
}
int hi(int x){
	int h=0,cnt=0;
	while(x){
		cnt++;
		if(x&1)h=cnt;
		x>>=1;
	}
	return h;
}
void solve(){
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
//	if(n<=20){
//		dfs(0,0,0);
//		cout<<ans;
//		return ;
//	}
	sort(a+1,a+n+1,cmp);
	if(m==1)cout<<a[1];
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
	}
	vector<ll>v[35];
	for(int i=1;i<=n;i++){
		int x=hi(a[i]);
		v[x].push_back(a[i]);
		
	}
	int ans=-1;
	for(int i=34;m;i--){
		if(v[i].size()<2)continue;
		sort(v[i].begin(),v[i].end(),cmp);
		int si=v[i].size();
		for(int j=0;j<si and m;j++){
			if(ans==-1)ans=v[i][j];
			else ans&=v[i][j];
			m--;
		}
		
	}
	cout<<ans;
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
