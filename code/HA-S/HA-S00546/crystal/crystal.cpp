#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],f[500005],maxx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	int l=1;
	for(int i=2;i<=n;i++){
		int sum=f[i-1]-f[l-1];
		int k=i-l;
		int ans=k*a[i];
		int t=ans-sum;
		while(t>m){
			t-=a[i]-a[l];
			k--;
			l++;
		}
		k++;
		maxx=max(k,maxx);
	}
	cout<<maxx;
	return 0;
} 
