#include<bits/stdc++.h>
using namespace std;
int a1,b1;string a2,b2;int c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a2[2]=='D')a2[2]='E';
	if(a1==b1){
		c1=1;
		if(a2[1]==b2[1]&&a2[0]==b2[0])
		{
			c2=1;
			if(a2[2]<'D'&&b2[2]<'D'||a2[2]>'D'&&b2[2]>'D')
			{
				c3=1;
				if(a2[2]-b2[2]==1||a2[2]-b2[2]==-1)
				c4=1;
			}
		}
	}
	cout<<c1<<c2<<c3<<c4;
	return 0;
}
