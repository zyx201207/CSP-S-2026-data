#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	int pai1=0,pai2=0;
	pai1=(s1[0]-'0')*10+s1[1]-'0';
	pai2=(s2[0]-'0')*10+s2[1]-'0';
	if(pai1==pai2) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	char hao1,hao2;
	hao1=s1[2];
	hao2=s2[2];
	if((hao1<='C'&&hao2<='C')||(hao1>='D'&&hao2>='D')) cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(hao1-hao2)==1)	cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
