#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
struct node
{
	long long a;
	char b;
}str[1000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i].a;
		cin>>str[i].b;
	}
	int l=1;
	int r=n;
	while(l<r)
	{
		if(str[l].b!=str[r].b)
		{
			if(str[l].a<str[r].a)
			{
				sum+=str[l].a;
				str[r].a-=str[l].a;
				str[l].a=0;
			}
			else
			{
				sum+=str[r].a;
				str[l].a-=str[r].a;
				str[r].a=0;
			}
		}
		else
		{
			str[l].a--;
			str[r].a--;
		}
		if(str[l].a==0)
		{
			l++;
		}
		if(str[r].a==0)
		{
			r--;
		}
	}
	cout<<sum;
} 
