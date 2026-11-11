#include<bits/stdc++.h>
using namespace std;
struct nom{
	char c;
	long long l;
}s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i = 0;i<n;i++)
	{
		cin>>s[i].l>>s[i].c;
	}
	long long i = 0,j = n-1,cnt = 0;
	while(i < (n+1)/2 || j > (n+1)/2) 
	{
		if(s[i].c == s[j].c)
		{
			if(s[i].l != s[j].l)
			{
				if(s[i].l > s[j].l)
				{
					s[i].l -= s[j].l;
					j--;
				}
				else
				{
					s[j].l -= s[i].l;
					i++;
				}
			}
			else
			{
				i++;
				j--;
			}
		}
		else
		{
			if(s[i].l > s[j].l)
			{
				cnt += s[j].l;
				s[i].l -= s[j].l;
				j--;
			}
			else if(s[i].l<s[j].l)
			{
				cnt += s[i].l;
				s[j].l -= s[i].l;
				i++;
			}
			else
			{
				cnt += s[i].l;
				i++;
				j--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
