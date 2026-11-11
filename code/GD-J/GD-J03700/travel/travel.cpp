#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,c2,w1,w2;
int main()
{
 	freopen("tracel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>w1>>c2>>w2;
	if(c1==c2)cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	 } 
	if(w1[0]==w2[0]&&w1[1]==w2[1])cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((w1[2]>='A'&&w1[2]<='C'&&w2[2]>='A'&&w2[2]<='C')||(w1[2]>='D'&&w1[2]<='F'&&w2[2]>='D'&&w2[2]<='F'&&w1[2]!='E'&&w2[2]!='E')) cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if((w1[2]=='A'&&w2[2]=='B')||(w1[2]=='B'&&w2[2]=='A')||(w1[2]=='B'&&w2[2]=='C')||(w1[2]=='C'&&w2[2]=='B')||(w1[2]=='D'&&w2[2]=='F')||(w1[2]=='F'&&w2[2]=='D'))cout<<1;
	else
	{
		cout<<0;
	}
	return 0;
}

