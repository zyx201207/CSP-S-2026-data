#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c3,sc2,sc4;
	char c2,c4;
	cin>>c1>>sc2>>c2>>c3>>sc4>>c4;
	if(c1==c3)
	{
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(sc2==sc4)
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
		
	if((c2=='E'&&c4=='D')||(c4=='E'&&c2=='D'))//(c2[2]==c4[2]+1||c2[2]==c4[2]+1)&&(c2[2]!='D'&&c4[2]!='D')
	{
		cout<<11;
	}else if(c4<='C'&&c2<='C')
	{
		if(c4-c2==1||c2-c4==1)
			cout<<"11";
		else
			cout<<"10";
	}else
		cout<<"00";
}
