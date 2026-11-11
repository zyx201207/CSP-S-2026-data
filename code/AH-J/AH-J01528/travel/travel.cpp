#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[10],c2[10],c3[10],c4[10];
	for(int i=1;i<=2;i++)cin>>c1[i]; 
	for(int i=1;i<=3;i++)cin>>c2[i]; 
	for(int i=1;i<=2;i++)cin>>c3[i]; 
	for(int i=1;i<=3;i++)cin>>c4[i]; 
	if(c1[1]==c3[1]&&c1[2]==c3[2])
	{
		cout<<1;
		if(c2[1]==c4[1]&&c2[2]==c4[2])
		{
			cout<<1;
			if((c2[3]>='A'&&c2[3]<='C'&&c4[3]>='A'&&c4[3]<='C')||(c2[3]>='D'&&c2[3]<='F'&&c4[3]>='D'&&c4[3]<='F'))
			{
				cout<<1;
				if(((c2[3]>='A'&&c2[3]<='C'&&c4[3]>='A'&&c4[3]<='C')&&(c2[3]+1==c4[3]||c4[3]+1==c2[3]))||((c2[3]>='D'&&c2[3]<='F'&&c4[3]>='D'&&c4[3]<='F')&&(c2[3]+2==c4[3]||c4[3]+2==c2[3])))
				{
					cout<<1;
				}
				else{cout<<"0";return 0;}
			}
			else{cout<<"00";return 0;}
		} 
		else{cout<<"000";return 0;}
	}
	else cout<<"0000";
	return 0;
}
