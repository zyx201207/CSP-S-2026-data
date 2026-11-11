#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],i,j,k,h,b[300005];
	string s="";
int main()
{	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	memset(b,0,sizeof(b));
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			s=s+char(a[j]+'0');
			if(s.find(char(a[j]+'0'))!=s.size()-1)
			{
				s=s.erase(s.find(char(a[j]+'0')))+char(a[j]+'0');
			}
		}
		h=s.size();
		for(k=0;k<h;k++)
		b[int(s[k]-'0')]++;
		
		s="";
	}
	for(i=1;i<=m;i++)
	cout<<b[i]<<" ";
	return 0;
}
