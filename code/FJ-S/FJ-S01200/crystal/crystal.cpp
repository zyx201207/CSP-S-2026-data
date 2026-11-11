#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
bool cmp(long long x,long long y){
	return x<y;
}
int ans;
bool check(int x){
	long long sum=0;
	for(int i=1;i<x;i++){
		sum+=(a[x]-a[i]);
		if(sum>m)return false;
	}
	if(sum<=m)return true;
	else return false;
}
int solve(){
	int l=0,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=solve();
	cout<<ans;
	return 0;
}
