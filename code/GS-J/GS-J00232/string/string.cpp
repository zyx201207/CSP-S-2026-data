#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	string s,s1='';
	cin>>n;
	if(n==1)
	{
		cin>>a>>s;
		cout<<"0";
	}
	else if(n==2)
	{
		int b[2],c=0
		while(n--)
		{
			cin>>a>>s;
			b[c]=a;
			while(a--)
				s1+=s;
			if(s==s1[0])
				cout<<"0";
			else
				cout<<min(c[0],c[1]);
			c++;
		}
	}
	return 0;
}
