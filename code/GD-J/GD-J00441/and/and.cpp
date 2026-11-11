#include<bits/stdc++.h>
#define int int_fast64_t
using namespace std;
int a[int(5e5+5)];
bool cmp(int x,int y){
	if(__builtin_popcount(x)!=__builtin_popcount(y))return __builtin_popcount(x)>__builtin_popcount(y);
	else return x>y;
}
set<int> ejz;
bool ej(int x,int y){
	int ejx=*ejz.lower_bound(x),ejy=*ejz.lower_bound(y);
	if(x==0)ejx=1<<30;
	if(y==0)ejx=1<<30;
	if(ejx-x!=ejy-y)
	return ejx-x<ejy-y;
	else return x>y;
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=30;i++){
		ejz.insert((1<<i)-1);
	}
	int n,m;
	cin>>n>>m;
	int maxn=0;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)f=0;
		maxn=max(maxn,a[i]);
	}
	if(f){
		sort(a+1,a+n+1,ej);
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
			cerr<<a[i]<<' ';
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
