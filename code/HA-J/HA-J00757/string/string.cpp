#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long a[N],n,ans=0,sa=0,qi[200020]={0};
char c[N];
char ch(int as)
{
	for(int i=0;i<=n;i++)
	{
		if(as>qi[i]&&as<=qi[i+1])
		{
			return c[i+1];
		}
	}
}
void hui()
{
	int lo=sa;
	for(long long i=1,j=lo;i<=lo/2,j>=lo/2;i++,j--)
	{
		char abb=ch(i),aab=ch(j);
		if(abb!=aab)
		ans++;
	}
}
int bo()
{
	for(int i=1;i<n;i++)
	{
		if(c[i]!=c[i+1])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		qi[i]=a[i-1]+a[i];
		sa=sa+a[i];
	}
	int bbo=bo();
	if(bbo!=0)
		hui();
	cout<<ans;
	return 0;
}

