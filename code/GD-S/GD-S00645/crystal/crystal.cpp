#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m,a[100005],ans,s;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll j=1;j<=n;j++){
		ans=0;
		ll mm=m;
		ll p=upper_bound(a+1,a+n+1,a[j])-lower_bound(a+1,a+n+1,a[j]);
		ll w=lower_bound(a+1,a+n+1,a[j])-a;
		ans+=p;
		for(ll i=w-1;i>=1;i--){
			if(a[j]-a[i]<=mm){
				ans++;
				mm-=(a[j]-a[i]);
			}else{
				break;
			}
		}
		if(ans<s) break;
		s=max(s,ans);
	}
	cout<<s<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
