#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],c[500010],f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[1]=0;
	c[1]=c[0]=0;
	for(long long i=2;i<=n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]&&i<=n-1)f=0;
		b[i]=b[i-1]+a[i]-a[i-1];
		c[i]=c[i-1]+b[i];
	}
	if(f==1){
		for(long long i=n;i>=1;i--){
			if(c[i]<=m){
				cout<<i;
				return 0;
			}
		}
	}else{
		long long maxcnt=-1000;
		for(long long i=n;i>=2;i--){
			for(long long j=1;j<=i;j++){
				if(c[i]-c[j-1]<=m){
					if(i-j+1>maxcnt){
						maxcnt=i-j+1;
					}
				}
			}
		}
		cout<<maxcnt;
	}
	return 0;
}
