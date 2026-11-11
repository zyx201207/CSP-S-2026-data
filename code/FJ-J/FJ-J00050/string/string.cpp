#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
long long ans=0;
long long cnt=0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		char c1;
		cin>>x>>c1;
		if(c1==c[cnt])
		{
			a[cnt]+=x;
		}else{
			a[++cnt]=x;
			c[cnt]=c1;
		}
	}
	long long left=0;
	int where=0;
	for(int i=1,j=cnt;i<j;)
	{
		long long x=a[i];
		long long y=a[j];
		if(where==1) x=left;
		if(where==-1) y=left;
		if(x>y)
		{
			if(c[i] != c[j]) ans+=y;
			left=x-y;
			where=1;
			j--;
		}
		if(x==y)
		{
			if(c[i] != c[j]) ans+=y;
			left=0;
			where=0;
			i++;j--;
		}
		if(x<y)
		{
			if(c[i] != c[j]) ans+=x;
			left=y-x;
			where=-1;	
			i++;		
		}
	}
	cout<<ans;
}
