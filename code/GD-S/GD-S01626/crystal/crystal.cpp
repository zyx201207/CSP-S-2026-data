#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long f[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	f[0] = 0;
	for(int i = 1;i <= n;i++){
		f[i] = f[i-1] + a[i];
	}
	long long ans = 0;
	for(long long i = 1;i <= n;i++){
		if((f[i] + m) / i == a[i+1]){
			ans = max(ans,i+1);
		}
	}
	cout<<ans;
	return 0;
}
