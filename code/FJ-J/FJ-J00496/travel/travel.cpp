#include<bits/stdc++.h>
using namespace std;
char s1[3],s2[3];
string c1,c2;
int a[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a[0]=1;
	}	
	int d=s1[2]-'A',b=s2[2]-'A';
	if(s1[0]==s2[0]  && s1[1]==s2[1] && a[0]==1)
	{
		a[1]=1;
	}
	int n=0,m=0;
	if(s1[2]>='A' && s1[2]<='C')
	{
	n=1;
	}
	if(s2[2]>='A' && s2[2]<='C')
	{
	m=1;
   }
	if(m==n && a[1])
	{
		a[2]=1;
		if((!m && !n) ||(m && n && abs(d-b)==1))
		{
			a[3]=1;
		}
	 else if(!abs(d-b)) 
	{
		cout<<"0000";
		return 0;
	}
    }
	for(int i=0;i<4;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
 } 
