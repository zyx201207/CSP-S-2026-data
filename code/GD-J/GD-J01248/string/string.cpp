#include<iostream>
using namespace std;
struct shu{
	int a=0;
	char c=0;
}s[200005];


int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long  n,num=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
	}
	int l=1,r=n,i=0;
	char ls,rs;
	while(l<r)
	{
		int numl=s[l].a;
		int numr=s[r].a;
		if(numl==numr)
		{
			if(s[l].c!=s[r].c)
			{
				num+=numl;
			}
			s[r].a=0;
			s[l].a=0;
			l+=1;
			r-=1;
		}
		else if(numl>numr)
		{
			if(s[l].c!=s[r].c)
			{
				num+=numr;
			}
			s[r].a=0;
			s[l].a=numl-numr;
			r-=1;
		}
		else if(numl<numr)
		{
			if(s[l].c!=s[r].c)
			{
				num+=numl;
			}
			s[r].a=numr-numl;
			s[l].a=0;
			l+=1;
		}
	}
	cout<<num;
 } 

