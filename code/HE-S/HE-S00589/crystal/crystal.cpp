#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=-1;
vector<ll> a;
void dfs(ll x){
	if(x==0){
		vector<ll> b;
		for(int i=0;i<n;i++){
			b.push_back(a[i]);
		}
		sort(b.begin(),b.end());
		ll sum=1,num=b[1],ms=0;
		for(int i=1;i<n;i++){
			if(b[i]!=num){
				ms=max(ms,sum);
				sum=1;
				num=b[i];
			}
			else sum++;
		}
		ans=max(ms,ans);
		return;
	}
	for(int i=0;i<n;i++){
		a[i]++;
		dfs(x-1);
		a[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll pk;cin>>pk;
		a.push_back(pk);
	}
	dfs(m);
	cout<<ans;
	return 0;
}
