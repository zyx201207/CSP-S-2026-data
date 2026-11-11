#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 5e5+5;
long long a[MAXN];
long long sum[MAXN];
long long n,m;
long long ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i = 1;i<=n;i++){
		sum[i] = sum[i-1]+a[i];
	}
	for(long long i = 1,j = 1;j<=n;){
		if(m>=a[j]*(j-i+1)-sum[j]+sum[i-1]){
			ans = max(ans,j-i+1);
			j++;
		}
		else{
			i++;
		}
	}
	cout<<ans;
	return 0;
}
