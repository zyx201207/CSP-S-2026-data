#include<bits/stdc++.h>
using namespace std;
char s1[10],s2[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[1]==s2[1])
		{
			cout<<1;
			if((s1[2]<68&&s2[2]<68)||(s1[2]>67&&s2[2]>67))
			{
				cout<<1;
				if((s1[2]-s2[2]==1)||(s1[2]-s2[2]==-1))
				{
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";	
	}
	if(c1!=c2)
	{
		cout<<"0000";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
