#include<bits/stdc++.h>
using namespace std;
int c1,c2,x,y;
char s1,s2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	cin>>c1>>x>>s1>>c2>>y>>s2;
	if(c1==c2) 
	{
		cout<<1;
		if(x==y)
		{
			cout<<1;
			if((s1<='C'&&s2<='C')||(s1>='D'&&s2>='D'))
			{
				cout<<1;
				if(abs(int(s1-s2))==1) cout<<1;
				else cout<<0;
			}
			else
			{
				cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
