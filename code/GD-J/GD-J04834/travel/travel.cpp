#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;

int c1,s1,c2,s2;
char p1,p2;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>p1>>c2>>s2>>p2;
	
	bool flag=true;
	cout<<(flag&&c1==c2?1:0),flag&=(c1==c2);
	cout<<(flag&&s1==s2?1:0),flag&=(s1==s2);
	cout<<(flag&&((p1<='C')==(p2<='C'))?1:0),flag&=((p1<='C')==(p2<='C'));
	
	if(flag&&((p1<='C'&&p2<='C'&&abs(p1-p2)<2)||(p1>='D'&&p2>='D'))) cout<<1;
	else cout<<0;
	
	return 0;
}

