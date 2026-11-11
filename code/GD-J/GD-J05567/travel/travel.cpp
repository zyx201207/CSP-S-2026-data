#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
int fg=1;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	int t1=(s1[0]-'0')*10+s1[1]-'0';
	int t2=(s3[0]-'0')*10+s3[1]-'0';
	if (t1==t2) cout<<1;
	else
	{
		cout<<0;
		fg=0;
	}
	int t3=(s2[0]-'0')*10+s2[1]-'0';
	int t4=(s4[0]-'0')*10+s4[1]-'0';
	if (t3==t4&&fg) cout<<1;
	else
	{
		cout<<0;
		fg=0;
	}
	int c1=s2[2]-'A';
	int c2=s4[2]-'A';
	if (((c1<=2&&c2<=2)||(c1>=3&&c2>=3))&&fg) cout<<1;
	else
	{
		cout<<0;
		fg=0;
	}
	if (fg==0) cout<<0;
	else
	{
		if (abs(c1-c2)==1) cout<<1;
		else cout<<0;
	}
	return 0;
}
