#include<bits/stdc++.h>
using namespace std;
int f[3];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	int a1145=(a2[0]-'0')*10+(a2[1]-'0');
	int a145=(a4[0]-'0')*10+(a4[1]-'0');

	char e=a2[2];
	char e2=a4[2];

	if(a1==a3)
	{
		cout<<1;
		f[0]=1;
	}else{
		cout<<0;
	}

	if(f[0]==1)
	{
		cout<<1;
		f[1]==1;
	}else{
		cout<<0;
	}

	if(f[0]==1)
	{
		cout<<1;
		f[2]==1;
	}
	else{
		cout<<0;
	}

	if(f[0]==1&&f[1]==1&&f[2]==1)
	{
		cout<<1;
		f[3]==1;
	}
	else{
		cout<<0;
	}
	return 0;
}
