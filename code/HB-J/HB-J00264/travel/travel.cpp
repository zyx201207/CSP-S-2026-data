#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;bool is[4];
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) is[0]=true;
	else is[0]=false;
	if(is[0]&&c2[0]==c4[0]&&c2[1]==c4[1]) is[1]=true;
	else is[1]=false;
	if(is[1]&&((c2[2]<='C'&&c4[2]<='C')||(c2[2]>='D'&&c4[2]>='D'))) is[2]=true;
	else is[2]=false;
	if(is[2]&&abs(c2[2]-c4[2])==1) is[3]=true;
	else is[3]=false;
	for(int i=0;i<4;i++) cout<<is[i];
	return 0;
}
