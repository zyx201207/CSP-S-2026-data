#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],f[1000010];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxn=-1,sum=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i]; 
		maxn=max(a[i],maxn);
		sum=sum&a[i];	
	}
	if(m==1) {
		cout<<maxn;
		return 0;
	} 
	if(m==n) {
		cout<<sum;
		return 0;
	}
	if(m==2){
		long long ans,maxn=1;
		for(int i=1;i<=n;i++){
			ans=a[i];
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,ans&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	f[0]=maxn;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			f[j]=max(f[j],f[j-1]&a[i]);
	cout<<f[m];
	return 0;
}

