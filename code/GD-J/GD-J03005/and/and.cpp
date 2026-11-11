#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ma=2e5+5;
ll n,m,a[ma],ans=0,ct[10];
bool cmp(ll a,ll b){
	return a>b;
}
void dfs(int idx,int cnt,ll num){
	if(cnt>m){
		ans=max(num,ans);
		return;
	}
	for(int i=idx;i<=n-m+cnt;i++){
		dfs(i+1,cnt+1,num&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool st1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4)st1=0;
		else ct[a[i]]++;
	}
	if(n>2000){
		if(st1){
			ll sto=m;
			if(ct[3]>=m)cout<<3;
			else if(ct[2]+ct[3]>=m)cout<<2;
			else if(ct[1]+ct[3]>=m)cout<<1;
			else cout<<0;
			return 0;
		}
		sort(a+1,a+1+n,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	ll num=0,cnt=1;
	for(int i=1;i<=32;i++){
		num+=cnt;
		cnt*=2;
	}
	
	dfs(1,1,num);
	cout<<ans;
	return 0;
}
/*
*/
