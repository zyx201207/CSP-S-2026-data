#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll m,a[500005],c[500005],f[5005][5005];
int main(){
	freopen("crystal.in","r",stdin);//75
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		int maxn=-1;
		for (int i=1;i<=n;i++){
			c[i]=a[i]-a[i-1];
			f[1][n]+=a[n]-a[i];
		}
		for (int i=1;i<=n;i++){
			if(i!=1){
				f[i][n]=f[i-1][n]-(a[n]-a[i-1]);
				if(f[i][n]<=m)maxn=max(maxn,n-i+1);
			}
			for (int j=n-1;j>=i;j--){
				f[i][j]=f[i][j+1]-(j-i+1)*c[j+1];
				if(f[i][j]<=m)maxn=max(maxn,j-i+1);
			}
		}
		cout<<maxn;
	}else{
		bool fb=1;
		for (int i=1;i<n;i++){
			if(a[i]!=a[i+1]){
				fb=0;
			}
		}
		if(fb){
			cout<<n;
			return 0;
		}else{
			ll sum=0;
			for (int i=1;i<=n;i++){
				sum+=(a[i]-a[i-1])*(i-1);
				if(sum>m){
					cout<<i-1;
					return 0;
				}
			}
		}
	}
	return 0;
}
