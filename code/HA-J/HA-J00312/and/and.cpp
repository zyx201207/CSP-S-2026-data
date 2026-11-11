#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll num[200005],sum[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1);
	ll res=0;
	for(int i=1;i<=n-m+1;i++){
		ll k=num[i];
		for(int j=i+1;j<=i+m-1;j++){
			k&=num[j];
		}
		res=max(res,k);
	}
	cout<<res;
	return 0;
}

