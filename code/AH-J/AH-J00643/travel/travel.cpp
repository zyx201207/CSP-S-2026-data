#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s1,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	char ch1=s2[2],ch2=s4[2];
	s2.erase(2,1);
	s4.erase(2,1);
	
	if(s1==s3) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	if(s2==s4) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	
	if((ch1<='C'&&ch2<='C')||(ch1>='D'&&ch2>='D')) cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	
	if(ch1+1==ch2||ch2+1==ch1) cout<<1;
	else cout<<0;
	return 0;
}
