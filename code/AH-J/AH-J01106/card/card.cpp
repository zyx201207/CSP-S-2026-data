#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[500005];
string s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	}
	int st=0;
	while(st<n)
{
	for(int i=st;i<n;i++)
	{
	    int pos;
	    pos=s.find(a[i]+'0');
	    s+=a[i]+'0';
		if(pos!=-1)
		{
			s=s.erase(pos,(int)s.size()+1);
			s+=a[i]+'0';
		}
		if(s!="")
		{
			for(int i=0;i<=(int)s.size();i++)
			{
				t[s[i]-'0']++;
			}
		}
		else continue;
	}
	s="";
	st++;
}

	for(int i=1;i<=m;i++)
	{
		if(i>1)cout<<" ";
		cout<<t[i];
	}
	return 0;
}
