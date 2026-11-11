#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
bool f[5];
int main()
{
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2	;
    for(int i=1;i<=4;i++)f[i]=0;
	if(c1==c2)f[1]=1;
	f[2]=1;
	for(int i=1;i<=2;i++)
	{ 
	  if(s1[i]!=s2[i])
	  { 
		f[2]=0;
	    break;
	  }
	}
	f[3]=1;
    if((s1[3]-'A'<=2&&s2[3]-'A'>=3)||(s1[3]-'A'>=3&&s2[3]-'A'<=2))f[3]=0;
	if((s1[3]-'A'==s2[3]-'B')||(s2[3]-'A'==s1[3]-'B'))f[4]=1;
	
	for(int i=1;i<=4;i++)
	{
		if(f[i]==0)
		{
		  f[i++]=0;
	    }
		cout<<f[i];
	}
	
	return 0;
}
