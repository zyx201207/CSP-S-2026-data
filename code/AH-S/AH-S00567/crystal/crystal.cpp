#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],cnt[500005],ans=-1e18;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cnt[1]=0;
	for(ll i=2;i<=n;i++){
		cnt[i]=cnt[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(m>=cnt[j]-cnt[i]){
				ans=max((j-i),ans);
				}
			else break;						
			}
		} 
	cout<<ans+1;
	return 0;
}
