#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000+10];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ma=1;
	for(int i=2;i<=n;i++){
		long long ans=1,k=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=k){
				k-=(a[i]-a[j]);
				ans++;
			}
		}
		if(ma<ans)ma=ans;
	}
	cout<<ma;
	return 0;
} 


