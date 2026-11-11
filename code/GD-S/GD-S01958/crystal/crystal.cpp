#include <bits/stdc++.h>
using namespace std;
long long n , m;
long long a[500005];
long long sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=0;
	long long l=1;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-l+1)-(sum[i]-sum[l-1])>m){
			l++;	
		}
		ans=max(ans,(i-l+1));
	} 
	cout <<ans;
	return 0;
}
