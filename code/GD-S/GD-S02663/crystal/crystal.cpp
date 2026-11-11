#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,ans=-1;
	cin>>n>>m;
	long long a[n+5];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<i;j++){
			sum+=a[i]-a[j];
		}
		if(sum<=m and a[i+1]!=a[i]){
			ans=max(ans,i);
		}
		if(sum>m){
			cout<<ans;
			return 0;
		}
		sum=0;
	}
	cout<<ans;
	return 0;
} 
