#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
int n,a[N];
char b[N];
string sc;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++)
		{
			sc+=b[i];
		}
	}
	int k=sc.size();
	int k1=0,k2=k/2,ans=0;
	for(int i=k-1;i>=k2;i--)
	{
		if(sc[i]!=sc[k1])
		{
			ans++;
		}
		k2++;
	}
	cout<<ans;
	return 0;
}
