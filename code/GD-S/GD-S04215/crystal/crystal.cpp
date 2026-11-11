#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=0,ans;
long long a[500005],b[500005],c[500008];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f=1;
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		if(i>=2 && b[i]!=b[i-1]){
			f=0;
		}
	}
	if(f==1){
		for(int i=1;i<=n;i++){
			if((a[1]+a[i-1])*(i-1)/2>m){
				cout<<i-1;
				return 0;
			}
			ans=(a[1]+a[i-1])*(i-1)/2;
			cout<<ans<<' ';
		}
	}
	for(int i=n-1;i>=1;i--){
		c[i]=c[i+1]+b[i];
	}
	for(int i=1;i<n-1;i++){
		int p=i;
		long long sum=0;
		while(p<n && sum+(c[p]-c[p+1])*(p+1-i)<=m){
			sum+=(c[p]-c[p+1])*(p+1-i);
			p++;
		}
		cout<<sum<<' ';
		maxn=max(maxn,p-i+1);
	}
	cout<<maxn;
	return 0;
} 
