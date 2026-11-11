//GZ-J00172  遵义航天高级中学 王张煜麒 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	int s,a[2],b[3],c[2],d[3];
	cin>>c1>>s1>>c2>>s2;
		if(c1==c2)
		{
	 		s+1000;
		}
		else
		{
			s+0000;
		}
	for(int i=1;i=s1.size()-1;i++)
	{
		for(int j=1;j<=s2.size()-1;j++)
		{
		  	if(j==i)
		  	{
		  		s+100;	
			}
			else
			{
				s+000;	
			}	
		}
	}
	for(int i=1;i<=s1.size();i++)
	{
		cin>>a[i];
			for(int j=1;j<=s2.size();j++)
			{
				cin>>b[j];
				if(a[3]=='D'&&b[3]=='F'||a[3]=='F'&&b[3]=='D')
				{
					s+10;
				}
				else if(a[3]=='A'&&b[3]=='B'||a[3]=='B'&&b[3]=='A'||a[3]=='B'&&b[3]=='C'||a[3]=='C'&&b[3]=='B')
				{
					s+10;
				}
				else
				{
					s+00;
				}
			}
	}
	for(int i=1;i<=s1.size();i++)
	{
		cin>>c[i];
			for(int j=1;j<=s2.size();j++)
			{
				cin>>d[j];
				if(c[3]=='D'&&d[3]=='F'||c[3]=='F'&&d[3]=='D')
				{
					s+1;
				}
				else if(c[3]=='A'&&d[3]=='B'||c[3]=='B'&&d[3]=='A'||c[3]=='B'&&d[3]=='C'||c[3]=='C'&&d[3]=='B')
				{
					s+1;
				}
				else
				{
					s+0;
				}
			}
	}
	cout<<s;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

