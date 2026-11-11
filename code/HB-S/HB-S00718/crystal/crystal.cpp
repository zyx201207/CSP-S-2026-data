#include<bits/stdc++.h>
#define ll long long
using namespace std;
const unsigned long long RP=ULONG_LONG_MAX;
ll n,m,a[500010],s[500010],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
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
	for(int i=1;i<=n;i++){
		ll l=1,r=i-1,t=i;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-s[i-1]+s[mid-1]<=m){
				t=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-t+1);
	}
	cout<<ans;
	return 0;
}
