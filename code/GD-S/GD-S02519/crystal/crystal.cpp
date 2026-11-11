#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=1;
	ll cnt=a[2]-a[1];
	while(m>=cnt){
		m-=cnt;
		ans++;
		cnt+=cnt;
	}
	if(ans>n) ans=n;
	cout<<ans;
	return 0;
} 
