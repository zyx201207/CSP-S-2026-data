#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll a[500010],s[500010],m;
bool check(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-s[i]+s[i-x]<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}

