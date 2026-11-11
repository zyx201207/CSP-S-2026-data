#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans=1,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		k+=ans*(a[i]-a[i-1]);k-=a[i]-a[i-ans];
		while(i>ans&&(k+a[i]-a[i-ans])<=m){
			k+=a[i]-a[i-ans];ans++;
		}
	}
	cout<<ans;
	return 0;
}
