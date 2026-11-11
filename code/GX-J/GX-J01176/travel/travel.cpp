#include<bits/stdc++.h>
using namespace std;
int e[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]) e[0]=1;
	if(b[0]==d[0]&&b[1]==d[1]) e[1]=1;
	if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')) e[2]=1;
	if(e[0]==1&&e[1]==1&&e[2]==1){
		if(b[2]-d[2]==1||b[2]-d[2]==-1) e[3]=1;
	}   
	for(int i=0;i<4;i++) cout<<e[i];
	return 0;
}
