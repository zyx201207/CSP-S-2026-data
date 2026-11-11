#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll m;
ll a[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	
	int head=1,tail=0,ans=0;
	ll cst=0;
	for(int i=2;i<=n;i++){
		//假设此时以 a_i 为添加线
		tail++;
		ll ad=a[i]-a[i-1];
		cst+=(tail-head+1)*ad;
		while(cst>m && head<tail){
			cst-=(a[i]-a[head]);
			head++;
		}
		if(cst>m)continue;
		ans=max(ans,tail-head+2);
	}
	cout<<ans;
	return 0;
}
