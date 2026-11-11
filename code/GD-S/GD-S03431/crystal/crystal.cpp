#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll maxn=1;
ll a[500005];
vector<ll> s(500005);//前缀和快速求区间和 
bool cmp(ll b,ll c){
	return b<c;
}
bool check(int l,int r){
	if((r-l)*a[r]-(s[r-1]-s[l-1])<=m) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int last=1;
	for(int i=1;i<=n;i++){
		if(check(last,i)){
			maxn=max(maxn,i-last+ll(1));
		}
		else{
			for(int j=last;!check(j,i)&&j<=n&&j>=1;j++){
				last=j;
			}
			last++;
		}
	}
	cout<<maxn<<'\n';
	
	
	return 0;
}
