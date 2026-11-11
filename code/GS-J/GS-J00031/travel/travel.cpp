#include <bits/stdc++.h>;
using namespace std;
char n[15];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<11;i++)
		cin>>n[i];
	if(n[1]==n[6] && n[2]==n[7])
		{cout<<'1';
		if(n[3]==n[8] && n[4]==n[9])
			{cout<<'1';
			if((n[5]=='A' && n[10]=='B')||(n[5]=='A' && n[10]=='C')||(n[5]=='B' && n[10]=='A')||(n[5]=='B' && n[10]=='C')||(n[5]=='C' && n[10]=='A')||(n[5]=='C' && n[10]=='B')||(n[5]=='D' && n[10]=='F')||(n[5]=='F' && n[10]=='D'))
				{cout<<'1';
				if((n[5]=='A' && n[10]=='B')||(n[5]=='B' && n[10]=='A')||(n[5]=='B' && n[10]=='C')||(n[5]=='C' && n[10]=='B')||(n[5]=='D' && n[10]=='F')||(n[5]=='F' && n[10]=='D'))
					{cout<<'1';}
				else
					{cout<<'0';}}
			else
				{cout<<"00";}}
		else
			{cout<<"000";}}
	else
		{cout<<"0000";}
	return 0;
}
