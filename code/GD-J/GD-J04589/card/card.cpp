#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+5];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	stack<long long>b;
	int l=0,f=0,l1=0;
	char s='1';
	b.push(a[l]);
	int top=0;
	string k="";
	for(int i=l+1;i<n;i++)
	{
		if(a[i]==a[l])
		{
			b.pop();
			l=i;
			b.push(a[i]);
			k="";
			k+=char(a[i]+'0');
			l1=1;
			cout<<f;
			s=char(int(s)+1);
		}
		else 
		{
			k+=char(a[i]+'0');
			l1++;
			b.push(a[i]);
			for(int i=0;i<l1;i++)
			{
				if(s==k[i])
				{
					f++;
				}
			}
		}
		
	}
	return 0;
}
