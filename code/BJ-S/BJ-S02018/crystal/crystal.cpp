#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005],b[500005],c[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		c[i]=a[i]*(i-1)-b[i-1];
	}
	long long l=1,ans=1;
	for(long long r=2;r<=n;r++){
		long long k=c[r]-c[l]-l*(a[r]-a[l]);
		if(k<=m){
			ans=max(ans,r-l);
		}else{
			l++;
		}
	}
	cout<<ans;
}
