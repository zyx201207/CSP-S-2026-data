#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2,paihao1,paihao2;
char liehao1,liehao2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2<<endl;
	paihao1=paihao1+s1[0]+s1[1];paihao2=paihao2+s2[0]+s2[1];
	liehao1=s1[2];liehao2=s2[2];
	//cout<<paihao1<<" "<< paihao2<<" "<<liehao1<<" "<<liehao2;
	if(c1==c2)
	{
		cout<<'1';
		if(paihao1==paihao2)
		{
			cout<<'1';
			if(liehao1>='A'&&liehao1<='C'&&liehao2>='A'&&liehao2<='C'||(liehao1>='D'&&liehao1<='F'&&liehao2>='D'&&liehao2<='F'))
			{
				cout<<'1';
				if(abs(int(liehao1-liehao2))==1||liehao1=='D'&&liehao2=='F'||liehao1=='F'&&liehao2=='D') cout<<1;
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
 } 
