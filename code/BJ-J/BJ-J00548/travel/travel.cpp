#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
string x1,x2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2)
		cout<<1;
	else
		cout<<0;
	for(int i=0;i<=1;i++)
		x1+=c1[i],x2+=c2[i];
	if(x1==x2&&s1==s2)
		cout<<1;
	else
		cout<<0;
	if(((c1[2]>='A'&&c1[2]<='C')&&(c2[2]>='A'&&c2[2]<='C'))&&x1==x2&&s1==s2)
		cout<<1;
	else if(((c1[2]=='D'||c1[2]=='F')&&(c2[2]=='D'||c2[2]=='F'))&&x1==x2&&s1==s2)
		cout<<1;
	else
		cout<<0;
		
	if(x1==x2&&((c1[2]=='A'&&c2[2]=='B')||(c1[2]=='B'&&c2[2]=='A'))&&s1==s2)
		cout<<1;
	else if(x1==x2&&((c1[2]=='B'&&c2[2]=='C')||(c1[2]=='C'&&c2[2]=='B'))&&s1==s2)
		cout<<1;
	else if(x1==x2&&((c1[2]=='D'&&c2[2]=='F')||(c1[2]=='F'&&c2[2]=='D'))&&s1==s2)
		cout<<1;
	else
		cout<<0;
	return 0;
}
