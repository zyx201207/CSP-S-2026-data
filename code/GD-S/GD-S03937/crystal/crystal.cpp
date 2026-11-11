#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,m1,ans=1,ans2=1,a[20000000],b[20000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	ll l=n/2+1;

	for(int i=l-1;i>=1;i--){
		while(m1<=m && a[i]<a[l]){
			m1++;
			a[i]++;
		}
		if(m1<=m)ans++;
	}
	for(int i=l+1;i<=n;i++){
		if(a[i]==a[l]){
		ans++;
		}
		else break;
	}
	//====================
	for(int i=l+1;i<=n;i++){
		while(m1<=m && b[i]>b[l]){
			m1++;
			b[l]++;
		}
		if(m1<=m)ans2++;
	}
	for(int i=l-1;i<=n;i++){
		if(b[i]==b[l]){
		ans2++;
		}
		else break;
	}
	//cout<<ans<<" "<<ans2<<endl;
	cout<<max(ans,ans2);
	return 0;
} 
