#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],c[500010],d[500010];
int main(){
  	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			continue;
		}
		b[i-1]=a[i]-a[i-1];
	}
	long long sum=0;
	for(long long i=1;i<n;i++){
		c[i]=b[i]*i;
		d[i]=d[i-1]+c[i];
	}
	long long mx=0;
	for(long long l=1;l<n;l++){
		for(long long r=l+1;r<n;r++){
			if(d[r]-d[l-1]<=m){
				mx=max(mx,r-l+2);
			}
		}
	}

	cout<<mx;
	return 0;
}
