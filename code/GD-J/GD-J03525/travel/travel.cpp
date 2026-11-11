#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f_1,f2,f3,f4;
	f_1=f2=f3=f4=0;
	if(c1==c2)f_1=1;
	else {cout<<"0000";return 0;}
	if((s1[0]==s2[0])&&(s1[1]==s2[1]))f2=1;
	if(s1[2]<='C'&&s2[2]<='C'&&f2==1)f3=1;
	else if(s1[2]>='D'&&s2[2]>='D'&&f2==1)f3=1;
	if(f2==1&&f3==1&&(s1[2]-s2[2]==1||s2[2]-s1[2]==1))f4=1;
	cout<<f_1<<f2<<f3<<f4;
	return 0;
}
