//GZ-S00126 贵阳市第一中学 谢云龙 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int mx=1;
	int l=1;
	for(int i=2;i<=n;i++){
		while(1ll*(i-l+1)*a[i]-(sum[i]-sum[l-1])>m){
			l++;
		}
		mx=max(mx,i-l+1);
	}
	cout<<mx;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
