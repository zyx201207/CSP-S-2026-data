#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a="",d="",s="",z="",j="",q="",zz="";
	int p=0,i=0,u=0,y=0,x=0,c=0;
	cin>>a;
	cin>>s;
	cin>>d;
	cin>>z;
	j=s[2];
	q=z[2];
	p=s[1];
	u=z[1];
	if(a==d)
	{
		zz+="1";
		
	}
	else{
		zz+="0";
		zz+="0";
		zz+="0";
		zz+="0";
		cout<<zz;
		return 0;
	}
	if(p==u)
		{
			zz+="1";
		
		}
	else{
		zz+="0";
		zz+="0";
		zz+="0";
		cout<<zz;
		return 0;
	}
	if(j=="F"||j=="D")
			{
				if(q=="F"||q=="D")
				{
					zz+="1";
					zz+="1";
				}
				else{
					zz+="0";
					zz+="0";
				}
			}
		else{
			if(q=="A")
			{
				zz+="1";
				if(j=="B")
				{
					zz+="1";
					}
					else{
						zz+="0";
					}	
			}
				else{
					if(q=="C")
					{
						zz+="1";
						if(j=="B")
						{
							zz+="1";
						}
						else{
							zz+="0";
						}
					}
					else{
						if(q=="B")
						{
							zz+="1";
							zz+="1";
						}
						else{
							zz+="0";
							zz+="0";
						}
					}
				}
			}
	cout<<zz;
	
	
	

	return 0;
}
