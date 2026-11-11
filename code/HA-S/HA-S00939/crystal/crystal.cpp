#include<bits/stdc++.h>
using namespace std;
long long a[10001],b[1001][1001],c[10001],d[10001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=a[1];i<=a[n];i++){
		for(int j=1;j<=n;j++){
			b[i][j]=abs(i-a[j]);
		}
	}
	for(int i=a[1];i<=a[n];i++){
		for(int j=1;j<=n;j++){
			if(c[i]>m){d[i]++;}
			c[i]+=b[i][j];
		}
	}               
	for(int i=a[1];i<=a[n];i++){
		d[i]=n-d[i]-1;
	}
	for(int i=a[1];i<=a[n];i++){
		if(d[i]>=maxn) maxn=d[i];
	}
	cout<<maxn;
	return 0;
}
