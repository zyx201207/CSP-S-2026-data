#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,b;int n;long long aa[200005];string cc[200005];
	cin>>n;
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i]>>cc[i];
		s+=aa[i];
	}
			long long ss=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=aa[i];j++)
		{
			ss++;
			if(ss>s/2)
			{
				b+=cc[i];
			}else
			{
				a+=cc[i];
			}
		}
	}
	long long ans=0;

	for(int i=0;i<s/2;i++)
	{
		//cout<<a[i]<<a[a.size()-i];
		if(a[i]!=b[i])
		{
			ans++;
		}
	}
	cout<<ans;
	
}
