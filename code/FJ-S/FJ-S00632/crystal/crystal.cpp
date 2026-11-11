#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]-a[1];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=sum[i];
		if(ans>m){
			cout<<i-1;
			return 0;
		}
	}
	if(m>=ans){
		cout<<n;
	}
	return 0;
}//2 2 3 3 3 4 4 4 4 5 5 5 5 5
//1 2 3 4 5 6 7 8 9 10 11 12 13 14
