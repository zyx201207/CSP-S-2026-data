#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a=0,b=0,c=0,d=0,e=0,f=0,g=0,i=0;
	
	string q="",w="",r="",y="",x="";
	cin>>a;
	b=a-1;
	int o[a];
	string p[a];

	for(i=0;i<a;i++)
	{
		cin>>o[i];
		cin>>p[i];
	}
	while(b!=c)	
	{
		if(p[c]==p[b])
		{
			if(o[c]<=o[b])
			{
				o[b]-=o[b];
				c++;
			}
			else{
				o[c]-=o[b];
				b--;
			}
		}
		else{
			if(o[c]<=o[b])
			{
				o[b]-=o[c];
				d+=o[c];
				c++;
				
			}
			else{
				o[c]-=o[b];
				d+=o[b];
				b--;
				
			}
		}
	}
	cout<<d;
	return 0;	
}
