#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n-1;i++){
		if(i+ans-1>n) break;
		ll he=0,ji=1;
		for(ll j=i+1;j<=n;j++){
			he+=ji*(a[j]-a[j-1]);
			ji++;
			if(he>m) break;
			if(j-i+1<=ans) continue;
			if((j-i+1)>ans){
				ans=j-i+1;
			}
		}
	}
	cout<<ans;
	return 0;
} 
