#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q=" ";
	string w=" ";
	string e=" ";
	string r=" ";
	getline(cin,q);
	getline(cin,w);
	getline(cin,e);
	getline(cin,r);
	int arr[6]={0};
	if(q[0]==e[0] and q[1]==e[1])
	{
		arr[0]=1;
		if(w[0]==r[0] and w[1]==r[1])
		{
			arr[1]=1;
			if(w[2]!='D' and r[2]!='D' and w[2]!='F' and r[2]!='F')
			{
				arr[2]=1;
				if(w[2]=='A' and r[2]=='B')
				{
					arr[3]=1;
				}
				else if(w[2]=='B' and r[2]=='C')
				{
					arr[3]=1;
				}
				else
				{
					arr[3]=0;
				}
			}
			else if(w[2]!='A' and r[2]!='A' and w[2]!='B' and r[2]!='B' and w[2]!='C' and r[2]!='C')
			{
				arr[2]=1;
			}
			else
			{
				arr[2]=0;
			}
		}
		else
		{
			arr[1]=0;
		}
	}
	else
	{
		arr[0]=0;
	}
	for(int z=0;z<4;z++)
	{
		cout<<arr[z];
	}
	return 0;
}
