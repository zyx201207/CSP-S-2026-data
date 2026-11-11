#include<bits/stdc++.h>
using namespace std;
namespace my_space{
	using ll = long long; 
	using exl = __int128;
	int constexpr N = 5e5+50;
	ll a[N]; 
	int main(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		ios::sync_with_stdio(0); 
		cin.tie(0),cout.tie(0);
		int n;
		ll m;
		cin>>n>>m;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		ll ans=0; 
		sort(a+1,a+1+n);
		ll temp = a[1];
		for(int i = 1;i<=n;i++){
			a[i]-=temp;
		}
		ll cnt=0,sum=0,w=1;
		for(int i = 1;i<=n;i++){
			sum+=(a[i]-a[i-1])*cnt;
			while(sum>m){
				sum-=(a[i]-a[w]);
				w++;
				cnt--;
			}
			ans = max(ans,i-w+1);
			cnt++;
		}
		cout<<ans<<'\n';
		return 0;
	} 
}
int main(){
	return my_space::main();
}
