#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long num[500050];
long long sum[500050];
long long Ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i = 1;i <= n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1);
	for (long long i = 1;i <= n;i++){
		sum[i] = sum[i-1]+num[n]-num[i];
	}
	for (long long i = 1;i <= n;i++){
		long long l = 1,r = i,ans = i;
		while (l <= r){
			long long mid = (l+r)/2;
			if (sum[i]-sum[mid-1]-(num[n]-num[i])*(i-mid+1) <= m){
				r = mid-1;
				ans = mid;
			}
			else{
				l = mid+1;
			}
		}
		Ans = max(Ans,i-ans+1);
	}
	cout<<Ans;
	return 0;
}
/*

*/
