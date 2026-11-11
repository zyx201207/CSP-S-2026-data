 #include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
string c1,c2,c3,c4;
int main()
{
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) 
	{
		cout<<"1";
		if(c2[0]==c4[0] && c2[1]==c4[1]) 
		{
			cout<<"1";
			if((c2[2]-'A'<=2 && c4[2]-'A'<=2) || (c2[2]-'A'==3 && c4[2]-'A'==5) || (c2[2]-'A'==5 && c4[2]-'A'==3)) 
			{
				cout<<"1";
				if((abs(c2[2]-c4[2])==1) || (c2[2]=='D' && c4[2]=='F') ||(c2[2]=='F' && c4[2]=='D')) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
