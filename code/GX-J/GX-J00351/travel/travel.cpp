#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,s,z;
	cin >> x >> y >> s >> z;
	if(x==s)
	{
		cout << "1";
		if((y[2]<='C'&&z[2]<='C')||(y[2]>='D'&&z[2]>='D'))
		    {
				cout << "1";
				if(y[0]==z[0]&&y[1]==z[1])
	            {   
					cout << "1";
			if((y[2]=='A'&&z[2]=='B')||(y[2]=='B'&&(z[2]=='A'||z[2]=='C'))||(y[2]=='C'&&z[2]=='B'))
				{
					cout << "1";
				}else if((y[2]=='D'&&z[2]=='F')||(y[2]=='F'&&z[2]=='D'))
				{
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
	     }else{
			 cout << "000";
		 }
		}else{
			cout << "0000";
		}
		return 0;
}
