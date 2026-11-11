#include<bits/stdc++.h>
using namespace std;
struct a
{
	int a1,b1;
	string a2,b2;
};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a ans;
	cin>>ans.a1>>ans.a2>>ans.b1>>ans.b2;
	if(ans.a1==ans.b1)
	{
		cout<<"1";
		if(ans.a2[0]*10+ans.a2[1]==ans.b2[0]*10+ans.b2[1])
		{
			cout<<"1";
			if((ans.a2[2]>'C' and ans.b2[2]>'C') or (ans.a2[2]<='C' and ans.b2[2]<='C'))
			{
				cout<<"1";
				if((ans.a2[2]==ans.b2[2]+1 or ans.a2[2]==ans.b2[2]-1) and (ans.a2[2]!='C' and ans.b2[2]!='D'))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
