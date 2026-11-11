#include<bits/stdc++.h>
using namespace std;
string c1,c2,z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>z1>>c2>>z2;
	if(c1!=c2)
		cout<<"0000";
	else if(!(z1[0]==z2[0]&&z1[1]==z2[1]))
		cout<<"1000";
	else if(!((z1[2]<='C'&&z2[2]<='C')||(z1[2]>='D'&&z1[2]>='D')))
		cout<<"1100";
	else{
		if(z1[2]<='C'&&abs((int)(z1[2]-z2[2]))==1)
			cout<<"1111";
		else if(z1[2]>'C'&&abs((int)(z1[2]-z2[2]))==2)
			cout<<"1111";
		else
			cout<<"1110";
	}
	return 0;
}

