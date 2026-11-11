#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll n,m,a[N],t[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	t[0]=a[0]=0;
	for(int i=1;i<=n;i++)t[i]=t[i-1]+(a[i]-a[i-1])*(i-1);
	for(int i=1;i<=n;i++){
		if(t[i]<=m){ans=max(ans,(ll)i);continue;}
		ll l=0,r=i;
		while(l<r){
//			cout<<l<<" "<<r<<"\n";
			ll md=(l+r)>>1;
			if(t[i]-(t[md]+md*(a[i]-a[md]))<=m)r=md;
			else l=md+1;
		}
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
} 
