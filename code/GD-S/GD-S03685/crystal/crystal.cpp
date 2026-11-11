#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum;
long long c[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long op=1;op<=n;op++){
		memset(c,0,sizeof c);
		for(long long i=op;i<=n-1;i++){
			if(a[i+1]!=a[i]){
				c[i+1]=2*c[i]+a[i+1]-a[i];
			}else{
				c[i+1]=c[i];
			}
			if(c[i]<=m){
				ans=max(ans,i-op+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
