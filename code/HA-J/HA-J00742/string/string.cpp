#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	int ans=0;
	int a[200005];
	string c;
	string s1,s2;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			s1[i]=s1[i]+c[i];
		}
	}
	int l=s1.size();
	int k=-1;
	for(int i=l;i>0;i--)
	{
		k++;
		s2[i]=s2[i]+s1[k];
	}
	for(int i=0;i<l;i++)
	{
		if(s1[i]==s2[i])
		{
			cout<<"0"<<endl;
		}
		else if(n%2!=0)
		{
			for(int j=0;j<n/2;j++)
			{
				for(int v=n/2+2,v<=n;v++)
				{
					if(a[j]!=a[v])
					{
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
