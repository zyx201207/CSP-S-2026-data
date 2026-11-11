#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxi=0;
ll a[500005],f[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(abs(f[i]-a[i]*(i-1)) <= m){
			maxi=i;
		}
	}
	cout<<maxi;
	return 0;
} 
