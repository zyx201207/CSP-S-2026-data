//GZ-J00494 贺举柱 遵义航天中学
#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5;
int a[N];
char s[N];
int b[N],c[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	long long sum=0,cs=0;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	if(sum%2==0)
	{
		for(int i=0;i<n/2;i++)
		{
			a[i]=b[i];
		}
		for(int i=n/2-1;i<n;i++)
		{
			a[i]=c[i];
		}
		for(int i=0;i<n;i++)
		{
			if(b[i]!=c[i])
			{
				cs++;
			}
		}
	}
	else
	{
		for(int i=0;i<n/2+1;i++)
		{
			a[i]=b[i];
		}
		for(int i=n/2-2;i<n;i++)
		{
			a[i]=c[i];
		}
		for(int i=0;i<n;i++)
		{
			if(b[i]!=c[i])
			{
				cs++;
			}
		}
	}
	cout<<cs;
	return 0;
}

