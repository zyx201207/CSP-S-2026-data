#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,c;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c=a[2]-a[1];
	long long ans=1;
	while(m-c*ans>0){
		m-=(c*ans);
		ans++;
	}
	cout<<min(ans,n);
	return 0;
}
