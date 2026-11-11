#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1!="01"&&c1!="16")
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			char ch1=s1[2],ch2=s2[2];
			if(ch1<='C'&&ch2<='C') 
			{
				cout<<"1";
				if(abs(ch1-ch2)==1) cout<<"1"<<'\n';
				else cout<<"0"<<'\n';
				
			}
			else if(ch1>='D'&&ch2>='D')
			{
				cout<<"1";
				if(abs(ch1-ch2)==1) cout<<"1"<<'\n';
				else cout<<"0"<<'\n';
			}
			else cout<<"00"<<'\n';
		}
		else cout<<"000"<<'\n';
	}
	else cout<<"0000"<<'\n';
	return 0;
}

