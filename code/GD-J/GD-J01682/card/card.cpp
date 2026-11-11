#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m;
long long p[300005];
long long f[500005];
long long b[300005];
long long t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=i;
		if(p[a[i]])
		{
			for(int j=p[a[i]]+1;j<=i-1;j++)
			{
				if(t[j])
				{
					if(t[j]<p[a[i]])
					f[j]=f[j]+t[j]-p[a[i]];
				}
				else f[j]-=p[a[i]];
				if(p[a[j]]<p[a[i]])f[j]+=f[p[a[j]]];
				t[j]=p[a[i]];
			}
		}
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		b[a[i]]=max(b[a[i]],f[i]);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
