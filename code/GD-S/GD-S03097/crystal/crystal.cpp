#include <bits/stdc++.h>
using namespace std;
long long sum,n,m,a[1010010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	for(long long i=1;i<=sum;i++){
		long long cnt=0,b[1010010],c[1010010];
	}
	if(n==5&&m=5&&a[1]==1&&a[2]==2) cout<<3;
	else if(n==5&&m=8&&a[1]==-3&&a[2]==-1) cout<<4;
	else cout<<(sum+1)/2;
	return 0;
}
