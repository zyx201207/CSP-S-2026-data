#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
int n;
ll m,ans=0;
void dfs(int w,int d,ll s,int k){
	if(a[w]<=k){
		if(w>n){
			ans=max(ans,s);
			return ;
		}
		if(d+(k-a[w])<=m) dfs(w+1,d+(k-a[w]),s+1,k);
		else{
			ans=max(ans,s);
			return ;
		}	
	}
	dfs(w+1,d,s,k);
}
bool cmp(int x,int y) {return x>y;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		ll x=a[2]-a[1];
		cout<<(ll)(sqrt(8*m/x+1)-1)/2+1<<'\n';
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int k=a[n];k<=a[1];k++){
		dfs(1,0,0,k);
	}
	cout<<ans;
	return 0;
}
