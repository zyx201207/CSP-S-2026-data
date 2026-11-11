#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	int a[10000];
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int max=a[n];
	for(ll i=1;i<=m-1;i++){
		max=(max&a[n-i]);
	}
	cout<<max;
	return 0;
}

