#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans;
ll m;
vector<ll>a;
vector<pair<ll,int>>valid_sum;
inline pair<ll,int> check(int x){//计算有效的总代价及有效水晶数量 
	ll sum=0;
	int cnt=0;
	for(int i=x;i>=1;i--){
		if(sum+(a[x]-a[i])>m)break;
		sum+=(a[x]-a[i]);
		cnt++;
	}
	return {sum,cnt};
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n+1,0);
	valid_sum.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		valid_sum[i]=check(i);
	}
	l=n;
	for(int i=l;i>=1;i--){
		int res=valid_sum[i].second;
		ans=max(res,ans);
	}
	cout<<ans;
	return 0;
}

