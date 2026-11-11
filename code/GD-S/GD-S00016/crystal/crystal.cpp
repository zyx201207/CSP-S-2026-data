#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001],sum[500001];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]; 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int maxn=0,h=0;
	for(int i=1;i<=n;i++){
		while(h<i&&a[i]*(i-h-1)-(sum[i-1]-(h==0?0:sum[h-1]))>m)h++;
		//cout<<i<<" "<<h<<endl;
		maxn=max(maxn,i-h);
	}
	cout<<maxn;
	return 0;
} 
