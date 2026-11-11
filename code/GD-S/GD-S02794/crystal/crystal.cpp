#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==a[1]){
		cout<<n;
		return 0;
	}
	int maxn=0;
	int cnt=1;
	for(int i=n;i>=2;i--){
		cnt=1;
		ll x=m;
		for(int j=i-1;j>=1;j--){
			if(x>=a[i]-a[j]){
				x-=(a[i]-a[j]);
				cnt++;
			}
			else{
				maxn=max(maxn,cnt);
				break;
			}
		}
		maxn=max(maxn,cnt);
	}
	
	cout<<maxn;
	return 0;
}
