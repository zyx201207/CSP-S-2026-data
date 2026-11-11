#include<bits/stdc++.h>
using namespace std;
int a,b;
char aa[22],bb[22];
int main()
{
	freopen("travel .in","r",stdin);
	freopen("travel .out","w",stdout);
	cin>>a;
	cin>>aa[0]>>aa[1]>>aa[2];
	cin>>b;
	cin>>bb[0]>>bb[1]>>bb[2];
	if(a==b) cout<<1;
	else
	{
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	if(aa[0]==bb[0]&&aa[1]==bb[1]) cout<<"1";
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if((aa[2]=='A'||aa[2]=='B'||aa[2]=='C')&&(bb[2]=='D'||bb[2]=='F'))
	{
		cout<<0<<0;
		return 0;
	}
	else if((bb[2]=='A'||bb[2]=='B'||bb[2]=='C')&&(aa[2]=='D'||aa[2]=='F'))
	{
		cout<<0<<0;
		return 0;
	}
	cout<<1;
	if(abs(int(bb[2])-int(aa[2])==1))
	{
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}//Trick||Treat!
