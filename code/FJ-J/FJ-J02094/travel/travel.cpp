#include<bits/stdc++.h>
using namespace std;
bool flag1,flag2,flag3,flag4;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b)
		flag1=1;
	if(c[0]==d[0]&&c[1]==d[1])
		flag2=1;
	if(!flag1)
		flag2=0;
	if((c[2]<='C'&&d[2]<='C')||(c[2]>='D'&&d[2]>='D'))
		flag3=1;
	if(!flag2)
		flag3=0;
	if((c[2]<='C'&&d[2]<='C'&&abs(c[2]-d[2])==1)||(c[2]=='D'&&d[2]=='F')||(c[2]=='F'&&d[2]=='D'))
		flag4=1;
	if(!flag3)
		flag4=0;
	cout<<flag1<<flag2<<flag3<<flag4<<endl;
	return 0;
}
