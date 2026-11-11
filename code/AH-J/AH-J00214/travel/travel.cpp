#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a;
	cin>>a;
	string s1,s2;
	cin>>s1;
	int b;
	cin>>b;
	cin>>s2;
	if(a==b) cout<<1;
	else 
	{
		for(int i=1;i<=4;i++)
			putchar_unlocked('0');
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) putchar_unlocked('1');
	else
	{
		for(int i=1;i<=3;i++)
			putchar_unlocked('0');
		return 0;
	}
	if((s1[2]>='A'&&s2[2]<='C'&&s1[2]>='A'&&s1[2]<='C')||(s1[2]>='D'&&s2[2]<='E'&&s1[2]>='D'&&s1[2]<='E')) putchar_unlocked('1');
	else 
	{
		putchar_unlocked('0');
		putchar_unlocked('0');
		return 0;
	}
	if(s1[2]>='C'&&s2[2]<='D'&&s1[2]>='C'&&s1[2]<='D')
	{
		putchar_unlocked('0');
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) putchar_unlocked('1');
	else putchar_unlocked('0');
	return 0;
}
