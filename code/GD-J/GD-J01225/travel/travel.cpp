#include<bits/stdc++.h>
using namespace std;
string tra1,tra2,sea1,sea2;
int main()
{
	//freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>tra1>>sea1>>tra2>>sea2;
	if(tra1!=tra2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(sea1.substr(0,2)!=sea2.substr(0,2))
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	char c1=sea1[2],c2=sea2[2];
	if(c1<='C'&&c2<='C'||(c1>='D'&&c2>='D'))
	{
		cout<<1;
		if(c1=='A'&&c2=='C'||(c1=='C'&&c2=='A'))cout<<0;
		else cout<<1;
		return 0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
}
