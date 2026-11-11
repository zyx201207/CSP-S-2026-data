#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b[200005][35],c[35],d[35],w,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		for(;a>0;a/=2)
		{
			b[i][++c[i]]=a%2;
		}
		d[i]=c[i];
	}
	sort(d+1,d+n+1);
	w=d[n-m+1];
	a=1;
	for(int i=1;i<=n;i++) c[i]=1;
	for(int i=1;i<=w-1;i++) a*=2;
	for(int j=w;j>=1;j--)
	{
		int t=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i][j]==1&&c[i]==1) t++;
		}
		if(t>=m) 
		{
			ans+=a;
			for(int i=1;i<=n;i++)
			{
				if(b[i][j]==0) c[i]=0;
			}
		}
		a/=2;
	}
	cout<<ans;
	return 0;
}
