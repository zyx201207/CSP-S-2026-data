#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005],c[50005],mx=-1e12-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		memset(c,sizeof(c),0);
		mx=-1e12-1;
		long long sum=0,tot=1;
		for(long long j=1;j<=i;j++){
			c[j]=a[i]-a[j];
		}
		sort(c+1,c+i+1);
		while(sum<=m){
			tot++;
			sum+=c[tot-1];
		}
		mx=max(tot,mx);
	}
	cout<<mx;
	return 0;
} 
