#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
	freopen(and.in,"r",stdin);
	freopen(and.out,"w",stdout);
	long long m,n;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=a[n];
	for(long long i=n;i>=n-m+1;i--){
		ans&=a[i];
		cout<<ans<<' '<<endl; 
	}
	cout<<ans;
	return 0;
}
