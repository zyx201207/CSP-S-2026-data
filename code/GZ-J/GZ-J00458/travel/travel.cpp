//GZ-J00458 邓可为 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ee,ff;
bool pd1,pd2,pd3,pd4; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	
	pd1 = (a==c);
	pd2 = (pd1&&(b[0]+b[1])==(d[0]+d[1]));
	pd3 = (pd1&&pd2&&((b[2]>'C'&&d[2]>'C')||(b[2]<='C'&&d[2]<='C')));
	ee = abs(b[2]-d[2]);
	ff = abs((b[0]+b[1])-(d[0]+d[1]));
	
	if(pd1&&((ee==1&&pd3)||(ff==1&&b[2]==d[2])))
		pd4=1;
	else pd4 = 0;
	cout<<pd1<<pd2<<pd3<<pd4<<endl; 
	return 0;
} 
