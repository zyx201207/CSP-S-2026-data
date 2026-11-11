#include<bits/stdc++.h>
using namespace std;
string a[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++)
		cin>>a[i];
	if(a[0]==a[2])
		cout<<"1";
	else{
		cout<<"0000"<<endl;
		return 0;
	}	
	if(a[1][0]==a[3][0]&&a[1][1]==a[3][1])
		cout<<"1";
	else{
		cout<<"000"<<endl;
		return 0;
	}
	if(((int)(a[1][2]-a[3][2]<=2)||(int)(a[1][2]-a[3][2]>=-2)&&(a[1][2]=='c'&&a[3][2]<'c')&&((a[1][2]=='b'&&a[3][2]<'c'))))
		cout<<"1";
	else{
		cout<<"00"<<endl;
		return 0;
	}
	if((int)(a[1][2]-a[3][2]==1)||(int)(a[1][2]-a[3][2]==-1))
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
