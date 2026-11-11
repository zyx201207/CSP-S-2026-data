#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],cut=0,k=0;
char b[200010];
string d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=k;j<k+a[i];j++)
		{
			d+=b[i];
		}
		k+=a[i];
		cut=(cut+a[i]+1)/2;
	}
	long long ans=0;
	for(int i=0;i<=cut;i++)
	{
		if(d[i]!=d[k-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
