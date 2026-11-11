#include<bits/stdc++.h>
using namespace std;

bool ans[4];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w".stdout);
	
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) ans[0]=1;
	if(ans[0] && b.substr(0,2)==d.substr(0,2)) ans[1]=1;
	if(ans[1] && ((b.substr(2,1)[0]<='C' && d.substr(2,1)[0]<='C')||
		(b.substr(2,1)[0]>='D' && d.substr(2,1)[0]>='D'))) ans[2]=1;
	if(ans[2] && abs(b.substr(2,1)[0]-d.substr(2,1)[0])==1) ans[3]=1;
	for(int i=0;i<4;i++) cout<<ans[i];
	
	return 0;
} 
