#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//cout<<"0";
	int n;
	cin>>n;
	
	int aa[n];
	string ab[n]={};
	string ac[n];
	int ans = 0;
	
	for(int i=0;i<n;i++)
	{
		cin>>aa[i]>>ac[i];
		if(ac[i]==ac[i+1])
		{
			cout<<"0";
			return 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=n;j>0;j--)
		{
			cin>>aa[i]>>ac[i];
			while(aa[i]>0)
			{
				ab[i]=ac[i]+ac[i];
				aa[i]-=2;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
