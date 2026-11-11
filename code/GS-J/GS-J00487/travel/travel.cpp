#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a[4];
	char c1[2],s1[4],c2[2],s2[4];
	string c3,c4,s3,s4;
	cin>>c3>>s3>>c4>>s4;
	for(int i;i<3;i++)
	{
		c1[i]=c3[i];
		c2[i]=c4[i];
		s1[i]=s3[i];
		s2[i]=s4[i];
	 } 
	if(c3!="01" || c3!="16" && c4 != "01" || c4!="16")
	{
		if(c3!=c4)
		{
			a[0]=false;
		}
		else if(c3==c4)
		{
			a[0]=true;
			if(s1[0]==s2[0] && s1[1]==s2[1])
			{
				a[1]=true;
				if((s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C'))
				a[2]=true;
				else if((s1[2]>='D' && s1[2]<='F') && (s2[2]>='D' && s2[2]<='F'))
				a[2]=true;
				else
				a[2]=false;
				if(s1[2]+1==s2[2] || s1[2]-1==s2[2])
				a[3]=true;
				else
				a[3]=false;
			}
			else
			{
				a[1]=false;
			}
		}

	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
}
