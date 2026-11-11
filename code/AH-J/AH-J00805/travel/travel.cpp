#include <bits/stdc++.h>
using namespace std;
bool check(char a,char b){
	if(a>b) swap(a,b);
	return (a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C')||(a=='D'&&b=='F');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a!=b)
	{
		cout<<"0000";
	}
	else
	{
		cout<<1;
		int sa=(s1[0]-'0')*10+s1[1]-'0';
		int sb=(s2[0]-'0')*10+s2[1]-'0';
		char wa=s1[2],wb=s2[2];
		if(sa==sb)
		{
			cout<<1;
		}
		else cout<<0;
		if(sa==sb&&check(wa,wb))
		{
			cout<<1;
		}
		else cout<<0;
		if(sa==sb&&check(wa,wb)&&max(wa,wb)-min(wa,wb)==1)
		{
			cout<<1;
		}
		else cout<<0;
	}
	return 0;
}
