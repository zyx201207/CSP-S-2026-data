#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct node
{
	int a;
	char c;
}str[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i].a>>str[i].c;
	}
	while(l<r)
	{
		if(str[l].c!=str[r].c)
		{
		    ans+=min(str[l].a,str[r].a);
		    
		}
		if(str[l].a>str[r].a)
		{
			//ans+=str[r].a;
			str[l].a-=str[r].a;
			r--;
		}
		else if(str[l].a<str[r].a)
		{
			//ans+=str[l].a;
			str[r].a-=str[l].a;
			l++;
		}
		else
		{
			//ans+=str[r].a;
			r--,l++;
		}
		//cout<<ans<<' ';
	}
	cout<<ans;
}
