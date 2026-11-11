#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000010];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long sum1=0,sum2=0;
	for(int i=1;i<(n+1)/2;i++) 
		sum1+=a[(n+1)/2]-a[i];
	if(sum1==m){
		int x=0;
		for(int i=1;i<=n;i++)
			if(a[i]==a[(n+1)/2])
				x++;
		cout<<(n+1)/2+x-1;
		return 0;
	}
	for(int i=(n+1)/2;i<n;i++) 
		sum2+=a[n]-a[i];
	if(sum2==m){
		int x=0;
		for(int i=1;i<=n;i++)
			if(a[i]==a[(n+1)/2])
				x++;
		cout<<(n+1)/2+x-1;
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=m;i++){
		m-=i;
		if(m<=0) cout<<i+1;
		return 0; 
	}
	return 0;
}
