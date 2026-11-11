#include <bits/stdc++.h>
using namespace std;
long long n,a[100005],d,i,z,sum;
char c[100005];
string s,shd,sh;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++) cin>>a[i]>>c[i];
	for(long long i=0;i<n;i++) z+=a[i];
	for(long long i=0;i<z;i++)
	{
		for(long long j=0;j<a[i];j++)
			s+=c[i];
	}
	d=s.size()/2;
	for(long long i=0;i<d;i++) shd[i]=s[i];
	for(long long i=0;i<d;i++)
	{
		for(long long j=d;j>0;j--)
			sh[i]=shd[j];
	}
	for(long long i=0;i<d;i++)
	{
		if(s[i+d]!=sh[i])
			sum++;
	}
	cout<<sum;
	return 0;
}
