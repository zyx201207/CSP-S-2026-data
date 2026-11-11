///GZ-J00537,贵阳市华麟学校,任瑞阳 
#include <iostream>
#include <cstdio>
using namespace std;
int main{
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	int r1,x1;
	string r2,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1&&r1!=1&&r1!=16)cout<<"1";
	else cout<<"0";
	if(int(r2[1:1])==int(x2[1:1]))cout<<"1";
	else cout<<"0";
	if(int(r2[1:2:1])!='C'&&int(r2[1:2:1])!='D')cout<<"1";
	else cout<<"0";
	if(int(r2[1:2:1])+1==int(x2[1:2:1])||int(r2[1:2:1])+1==int(x2[1:2:1]))cout<<"1";
	else cout<<"0";
	return 0; 
	 
}
