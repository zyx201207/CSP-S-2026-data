#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,c=0,p[500005],pa=0,pb=0;
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i)pa++;
		if(i>=2&&a[i]-a[i-1]==a[2]-a[1])pb++;
	}
	if(pa==n){
		long long c1=0,i=1;
		while(m-i>=0)
		{
			m-=i;
			i++;
			c1++;
		}
		if(c1>=n)cout<<n;
		else cout<<c1+1;
		return 0;
	}
	if(pb==n-1){
		long long c1=0,i=1;
		while(m-i>=0)
		{
			m-=i;
			i+=a[2]-a[1];
			c1++;
		}
		if(c1>=n)cout<<n;
		else cout<<c1+1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
	}
	for(long long i=n;i>=1;i--){
		for(long long j=1;j+i-1<=n;j++){
			long long k=j+i-1;
			long long z=p[k]-p[j-1]+m;
			z/=i;
			if(z>=a[k])
			{
				c=i;
				break;
			}
		}
		if(c)break;
	}
	cout<<c;
    return 0;
}

