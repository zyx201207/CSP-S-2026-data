//GZ-J00009 观山湖区铭苑中学 吴金源 
#include<bits/stdc++.h>
using namespace std;
int r1,x1;
string r2,x2;
void yyy(char r,char x)
{
	if(r1!=x1)
		cout<<"0000"<<endl;
	else if(r2[0]!=x2[0] || r2[1]!=x2[1])
		cout<<"1000"<<endl;
	else if((r=='A' && x=='B') || (r=='B' && x=='C') || (r=='D' && x=='F'))
		cout<<"1111"<<endl;
	else if((r=='B' && x=='A') || (r=='C' && x=='B') || (r=='F' && x=='D'))
		cout<<"1111"<<endl;
	else if((r=='A' && x=='C') || (r=='C' && x=='A'))
		cout<<"1110"<<endl;
	else
		cout<<"1100"<<endl;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	yyy(r2[2],x2[2]);
	return 0;
} 
