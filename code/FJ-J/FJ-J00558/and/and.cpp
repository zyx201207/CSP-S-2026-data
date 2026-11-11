#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b,c=0;
long long q(long long x,long long z,long long y){
	if(z>m){
		c=max(c,y);
		return 0;
	}
	for(int i=x;i<=n;i++){
		q(i+1,z+1,a[i]&a[x]);
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			b=a[i];
		}else{
			b=b&a[i];
		}
		c=max(a[i],c);
	}
	if(m==1){
		cout<<c;
	}else if(m==n){
		cout<<b;
	}else if(m==2){
		c=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				c=max(c,a[i]&a[j]);
			}
		}
		cout<<c;
	}else{
		c=0;
		for(int p=1;p<=n-m+1;p++){
			q(p+1,0,a[p]);
		}
		cout<<c;
	}
	return 0;
}
