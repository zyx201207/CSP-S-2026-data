#include<bits/stdc++.h>
using namespace std;
int k[4];
int main()
{
	freopen("tavel.in","r",stdin);
	freopen("tavel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char s=b[2],f=d[2];
	
	
	if(a[0]==c[0]&&a[1]==c[1])
	{
		k[0]=1;
		if(b[0]==d[0]&&b[1]==b[1])
		{
			k[1]=1;
			if((s<='c'&&f<='c')||(s>='d'&&f>='d')) 
			{
			    k[2]=1;
				if(s+1==f||f+1==s)
				{
					k[3]=1;
				}
			}
		}
	}
	for(int i=0;i<=3;i++)
	{
		cout<<k[i];
	}
	return 0; 
} 
