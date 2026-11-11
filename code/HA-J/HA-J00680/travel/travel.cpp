#include<bits/stdc++.h>
using namespace std;
int n1,n2;
string s1,s2;
int a[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	int pai1 = (s1[0]-'0')*10+(s1[1]-'0');
	int pai2 = (s2[0]-'0')*10+(s2[1]-'0');
	if(n1==n2)
	{
		a[0] = 1;	
		if(pai1==pai2)
		{
			a[1] = 1;
			if((s1[2]-'A'<3&&s2[2]-'A'<3)||(s1[2]-'A'>=3&&s2[2]-'A'>=3))
			{
				a[2] = 1;
				if(max(s1[2]-'A',s2[2]-'A')-min(s1[2]-'A',s2[2]-'A')==1)
				{
					a[3] = 1;
				}
			}
		}
	}
	for(int i = 0;i<4;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
