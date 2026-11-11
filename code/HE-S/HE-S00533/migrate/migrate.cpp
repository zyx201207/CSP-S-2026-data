#include <bits/stdc++.h>
using namespace std;
long long c1,t;
long long ans[1000000];
long long a[1000000],b[1000000],c[1000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c1>>t;
	for(long long e=0;e<t;e++){
		long long m,n;
		cin>>m>>n;
		for(long long i=1;i<=m;i++){
			cin>>a[i];
			b[i-1]=a[i]-a[i-1];
		}
		long long l=1;
		for(long long i=1;i<=m-1;i++){
			if(b[i]+b[i+1]<=n && b[i+1]+b[i+2]<=n &&  b[i]+b[i+1]+b[i+2]>n){
				c[l++]=i;
			}
		}
		c[0]=1;
		c[l]=m;
		for(long long i=1;i<l;i++){
			if(c[i+1]-c[i]-2<0)continue;
			ans[e]+=(c[i]-c[i-1]+1)*(c[i+1]-c[i]-2);
		}
	}
	for(long long i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}
