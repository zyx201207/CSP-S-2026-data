#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],sum;
long long c[114514];
long long cnt[50005],ans=1;
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		sum=0;
		for(int j=i-1;j>=1;j--){
			sum+=(a[i]-a[j]);
	}
	if(sum<=m)ans=i;
	}
	cout<<ans;
	return 0;
}
