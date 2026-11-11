#include<bits/stdc++.h>
using namespace std;
struct iny
{
	char a;
	long long l;
}a[200100];
int n;
long long cnl=0,cn=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		long long y;
		cin>>y;
		cnl+=y;
		char s;
		cin>>s;
		if(cn!=0&&a[cn-1].a==s)
		{
			a[cn-1].l+=y;
		}
		else
		{
			a[cn].l=y;
			a[cn++].a=s;
		}
	}
	long long cnt=0;
	if(cnl%2==0)
	{
		cnl/=2;
		int j=cn-1;
		for(int i=0;i<cn&&j>=i;)
		{
			if(a[i].a!=a[j].a)
			{
				if(a[i].l>a[j].l)
				{
					cnt+=a[j].l;
					a[i].l-=a[j].l;
					j--;
				}
				else
				{
					cnt+=a[i].l;
					a[j].l-=a[i].l;
					i++;
				}
			}
			else if(a[i].a==a[j].a)
			{
				if(a[i].l>a[j].l)
				{
					a[i].l-=a[j].l;
					j--;
				}
				else
				{
					a[j].l-=a[i].l;
					i++;
				}
			}
		}
	}
	else
	{
		cnl/=2;
		int j=cn-1;
		for(int i=0;i<cn&&j>i;)
		{
			if(a[i].a!=a[j].a)
			{
				if(a[i].l>a[j].l)
				{
					cnt+=a[j].l;
					a[i].l-=a[j].l;
					j--;
				}
				else
				{
					cnt+=a[i].l;
					a[j].l-=a[i].l;
					i++;
				}
			}
			else if(a[i].a==a[j].a)
			{
				if(a[i].l>a[j].l)
				{
					a[i].l-=a[j].l;
					j--;
				}
				else
				{
					a[j].l-=a[i].l;
					i++;
				}
			}
		}
	}
	cout<<cnt;
	
	/*string book;
	for(int i=0;i<n;i++)
	{
		long long y;
		char s;
		cin>>y>>s;
		for(long long j=0;j<y;j++)
		{
			book+=s;
		}
	}
	long long  b=book.size();
	
	long long cnt=0;
	if(b%2==0)
	{
		for(long long i=0;i<b/2;i++)
		{
			if(book[i]!=book[b-i-1])
			{
				
				cnt++;
			}
		}
	}
	else
	{
		for(long long i=0;i<b-i;i++)
		{
			if(book[i]!=book[b-i-1])
			{
				cnt++;
			}
		}
	}
	*/
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
