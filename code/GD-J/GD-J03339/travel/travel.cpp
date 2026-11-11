#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int z,v;
	bool a1,a2,a3,a4;
	string c1,c2,s1,s2;cin>>c1>>s1>>c2>>s2;
	a1=c1[0]*10+c1[1]==c2[0]*10+c2[1];
	z=(s1[0]-'0')*10+s1[1];v=(s2[0]-'0')*10+s2[1];
	a2=z==v&&a1;z=s1[2]-'A';v=s2[2]-'A';
	a3=((z<3&&v<3)||(z>2&&v>2))&&a2;
	a4=((z-1==v)||(z+1==v))&&a3;
	cout<<a1<<a2<<a3<<a4; 
} 
