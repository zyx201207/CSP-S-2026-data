#include<bits/stdc++.h>
using namespace std;
string in1,in2,in3,in4;
bool a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>in1>>in2>>in3>>in4;
	if(in1==in3)a=true;
	if((in2[2]==in4[2])&&a)b=true;
	if((in2[0]==in4[0])&&(in2[1]==in4[1])&&a)c=true;
	if(b&&c&&a)d=true;
	cout<<a<<c<<b<<d;
	return 0;
}
