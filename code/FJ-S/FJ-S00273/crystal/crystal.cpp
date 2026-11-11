#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n=0,a[500009],m=0,ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ll k=0,kk=0;
		for(int j=i;j>=1;j--){
			if(kk+a[i]-a[j]>m)break;
			kk+=a[i]-a[j],k++;
		}
		if(k>ans)ans=k;
	}
	cout<<ans;
	return 0;
}

