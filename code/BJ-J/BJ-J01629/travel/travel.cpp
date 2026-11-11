#include<bits/stdc++.h>
using namespace std;
int c1,c2,o1,o2,m[10]={1,1,1,2,2};
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		int a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0');
		if(a==b)
		{
			cout<<1;
			o1=s1[2]-'A',o2=s2[2]-'A';
			if(m[o1]==m[o2])
			{
				cout<<1;
				if(o1-o2==-1||o1-o2==1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
