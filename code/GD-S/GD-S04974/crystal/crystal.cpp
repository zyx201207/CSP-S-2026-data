#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI ;
using namespace std;
long long n,m,k,ans=1,a[1234567],sum,x=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int j=2;j<=n;j++){
		sum+=(j-x)*(a[j]-a[j-1]);
		while(sum>m)sum-=a[j]-a[x],x++;
		ans=max(ans,j-x+1);
	}
	cout<<ans<<'\n';
	return 0;
}
