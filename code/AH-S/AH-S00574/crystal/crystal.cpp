#include<bits/stdc++.h>
using namespace std;
bool f=1;
long long m,n,s,t,a[500001],b[200001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];a[i]+=100000;}
	sort(a+1,a+n+1);t=a[2]-a[1];
	for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=t){f=0;break;}
	if(f)
	{
		m/=t;
		for(int i=1;i<=n;i++)
			if(s<=m)s+=i;
			else{cout<<i-1;return 0;}
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(a[j]!=a[j-1])b[a[j]]+=a[j]-a[i];
	for(int i=1;i<=n;i++)
		if(b[a[i]]<=m)s=i;
		else
		{
			long long ss=0;
			for(int j=1;j<=i-s;j++)
			{
				ss+=a[i]-a[j];
				if(b[a[i]]<=m){s=max(s,(long long)(i-j));break;}
			}
		}
	cout<<s;
}
