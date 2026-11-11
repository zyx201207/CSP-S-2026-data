#include<bits/stdc++.h>
using namespace std;

long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long l=0,r=n,sum=1;
	for(long long i=2;i<=n;i++){
		long long ans=1;
		long long k=m;
		for(long long j=i-1;j>0;j--){
			if(a[j]<a[i]){
				if(a[i]-a[j]<=k){
					k-=(a[i]-a[j]);
					ans++;
				}
				else{
					break;
				}
			}
			else{
				ans++;
				continue;
			}
		}
		if(ans>sum){
			sum=ans;
		}
	}
	cout<<sum;
	
}
