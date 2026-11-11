#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
long long sm[500010];
bool check(int num){
	for(int i=0;i+num<=n;i++){
		long long res=num*a[i+num]-(sm[i+num]-sm[i]);
		if(res<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sm[i]=sm[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
