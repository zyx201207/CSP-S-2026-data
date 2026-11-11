#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)
		a1=1;
	else cout<<"0000",exit(0);
	if(c2[0]==c4[0]&&c2[1]==c4[1])
		a2=1;
	else cout<<"1000",exit(0);
	if((c2[2]<='C'&&c4[2]<='C')||(c2[2]>'C'&&c4[2]>'C'))
		a3=1;
	else cout<<"1100",exit(0);
	if(abs(c2[2]-c4[2])==1)
		a4=1;
	else cout<<"1110",exit(0);
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
