#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
ll a[N],b,c,n,m,sum[N],ans[N],tot,T,mx;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	ll pos=1;
	for(ll i=1;i<=n;i++){
		while(pos<i&&a[i]*(i-pos)-(sum[i-1]-sum[pos-1])>m)pos++;
		ans[i]=i-pos+1;
	}
	for(ll i=1;i<=n;i++)mx=max(mx,ans[i]);
	cout<<mx;
	return 0;
}
/*
5 5
1 2 4 8 9

*/