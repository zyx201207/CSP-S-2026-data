#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
int a[N];
int b[N];
int main()
{
	//贵阳市第十九中学 刘臣耘 GZ-J00189
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int cnt=0;
	for(int i=1;i<=s.size();i++)
	{
		cin>>a[i];
	}
	for(int i=s.size();i>=1;i--)
	{
		cin>>b[i];
	}
	for(int i=1;i<=s.size();i++)
	{
		if(a[i]==b[i]) cout<<0;
		else
		{
			while(a[i]==b[i])
			{
				a[i]=s.size()/2-i/2;
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0; 
}                                              
