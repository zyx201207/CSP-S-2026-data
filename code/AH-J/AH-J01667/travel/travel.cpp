#include<bits/stdc++.h> 
using namespace std;
string a,b;
int n,m,f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	cin>>a;
	cin>>m;
	cin>>b;
    if(n!=m)
	{
		cout<<"0000";
		return 0;
	}
	f1=1;
	int a1=(int(a[0])-48)*10+(int(a[1])-48);
	int b1=(int(b[0])-48)*10+(int(b[1])-48);
	if(a1!=b1)
	{
		cout<<"1000";
		return 0;
	}
	char a2=a[2],b2=b[2];
	if((a2=='A'&&(b2=='B'||b2=='C'))||(a2=='B'&&(b2=='A'||b2=='C'))||(a2=='C'&&(b2=='B'||b2=='A'))||(a2=='D'&&b2=='F')||(a2=='F'&&b2=='D'))
	{
		f3=1;
	}
	else
	{
		cout<<"1100";
		return 0;
	}
	if((a2=='A'&&b2=='B')||(a2=='B'&&(b2=='C'||b2=='A'))||(a2=='C'&&b2=='B')||(a2=='D'&&b2=='F')||(a2=='F'&&b2=='D'))
	{
		f4=1;
	}
	else
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
