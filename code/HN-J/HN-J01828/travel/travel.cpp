#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char rc[3],xc[3],rz[4],xz[4];
	cin>>rc[1]>>rc[2]>>rz[1]>>rz[2]>>rz[3]>>xc[1]>>xc[2]>>xz[1]>>xz[2]>>xz[3];
	if((rc[1]!=xc[1])||(rc[2]!=xc[2]))
		cout<<"0000";
	else
		{
			cout<<"1";
			if((rz[1]!=xz[1])||(rz[2]!=xz[2]))
				cout<<"000";
			else
				{
					cout<<"1";
					if(((rz[3]=='A')||(rz[3]=='B')||(rz[3]=='C'))&&((xz[3]=='D')||(xz[3]=='E'))||
					((rz[3]=='D')&&(xz[3]!='E'))||
					((rz[3]=='E')&&(xz[3]!='D')))
						cout<<"00";
					else
					{
						cout<<"1";
						if(((rz[3]=='A')&&(xz[3]=='C'))||((rz[3]=='C')&&(xz[3]=='A')))
							cout<<"0";
						else
							cout<<"1";
					}
				}
		}
	return 0;
}
