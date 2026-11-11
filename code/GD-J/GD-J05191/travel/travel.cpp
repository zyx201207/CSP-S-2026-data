#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool b1,b2,b3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	b1=(c1==c3);
	b2=(b1? (c2[0]==c4[0]&&c2[1]==c4[1]):0);
	b3=(b2? (c2[2]<='C'&&c4[2]<='C')||(c2[2]>='D'&&c4[2]>='D'):0);
	cout<<b1<<b2<<b3<<(b3? (abs(c2[2]-c4[2])==1):0);
}
