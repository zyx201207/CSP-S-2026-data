#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],s[500005];
int n;
ll m;
bool check(int x,int lt){
	return (x-lt)*a[x]-(s[x-1]-s[lt-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n,mid;
		while(l<r){
			mid=(l+r+1)/2;
			if(check(mid,i))l=mid;
			else r=mid-1;
		}
		maxn=max(maxn,l-i+1);
	}
	cout<<maxn;
	return 0;
}
