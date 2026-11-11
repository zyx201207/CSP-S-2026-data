#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
int n;
ll m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	
	ll ans=-1e18;
	for(int i=n;i>=1;i--){
		ll cnt=m,cntn=1;
		for(int j=i-1;j>=1;j--){
			if(a[j]==a[i]){
				cntn++;
				for(int r=j+2;r<=n;r++){
					if(a[r]==a[i])cntn++;
					else break;
				}	
				continue;
			}
			ll sum=a[i]-a[j];
			if(sum<=cnt){
				cnt-=sum;
				cntn++;
			}	
		}
		 
		ans=max(ans,cntn);
	}
	cout<<ans;
	return 0;
}
