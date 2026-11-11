#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e5+5;
ll n,m;
ll a[N];
ll sum,z=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-z);
		while(z<=i&&sum>m){
			z++;
			sum-=a[i]-a[z-1];
		}
		ans=max(ans,i-z+1);
	}
	cout<<ans; 	
	return 0; 
}
