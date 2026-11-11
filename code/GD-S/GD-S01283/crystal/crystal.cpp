#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+4;
using ll = long long;
ll a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n>5000){
		ll tot=m;
		int ans=0;
		for(int j=2;j<=n;j++){
			if(tot>=(a[j]-a[j-1])*(j-1)){
				tot-=(a[j]-a[j-1])*(j-1);
				ans++;
			}
			else
				break;
		}
		cout<<ans<<"\n";
	}
	else{
		ll tot=m;
		int sum=1,ans=0;
		for(int i=1;i<=n;i++){
			tot=m,sum=1;
			for(int j=i+1;j<=n;j++){
				if(tot>=(a[j]-a[j-1])*(j-i)){
					tot-=(a[j]-a[j-1])*(j-i);
					sum++;
				}
				else
					break;
			}
			ans=max(ans,sum);
			if(n-i<=ans) break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
