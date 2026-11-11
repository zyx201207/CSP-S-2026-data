#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long a[500001],b[50001][50001]={0},c=0,maxx=1,aj=0,bj=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n-1;i++){
		if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
			aj=1;break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			bj=1;break;
		}
	}
	if(bj==0){
		for(int i=1;i<=m;i++){
			c=i*(i+1)/2;
			if(c>m){
				cout<<i-1;
				return 0;
			}
			if(c==m){
				cout<<i;
				return 0;
			}
		}
	}
	if(aj==0){
		int t=a[2]-a[1];
		for(int i=1;i<=m;i++){
			c=(a[n]+a[1])*n/2;
			if(c>m){
				cout<<i-1;
				return 0;
			}
			if(c==m){
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			b[i][j]=a[j+1]-a[j]+b[i][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			c+=b[i][j];
		}
	}
	if(c<=m){
		cout<<n;
		return 0;
	}
	for(int i=2;i<n;i++){
		for(int j=1;j<=n-i+1;j++){
			c=0;
			for(int k=1;k<=i;k++){
				c+=b[k][i-1];
			}
			if(c<=m){
				maxx=i;
			}
		}
	}
	cout<<maxx;
	return 0;
}
