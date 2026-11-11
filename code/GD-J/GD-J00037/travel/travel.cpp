#include<bits/stdc++.h>
using namespace std;

int a,b;
int pa,pb;
char ca,cb;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>pa>>ca>>b>>pb>>cb;
	if(a==b){
		cout<<"1";
		if(pa==pb)
		{
			cout<<"1";
			if((ca<='C'&&cb<='C')||(ca>'C'&&cb>'C'))
			{
				cout<<"1";
				if(ca==cb+1||ca==cb-1)
				{
					cout<<"1";
				}
				else	cout<<"0";
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
	else	cout<<"0000";
	return 0;
}
