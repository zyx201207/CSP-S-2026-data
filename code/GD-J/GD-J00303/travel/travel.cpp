#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		cout<<1;
		string a,b;
		a=s1[0]+s1[1],b=s2[0]+s2[1];
		if(a!=b) cout<<"000";
		else
		{
			cout<<1;
			char c=s1[2],d=s2[2];
			if(c>d) swap(c,d);
			if(c=='D'&&d=='F'||c=='A'&&d=='B'||c=='A'&&d=='C'||c=='B'&&d=='C') 
			{
				cout<<1;
				if(c=='A'&&d=='C') cout<<0;
				else cout<<1;
			}
			else cout<<"00";
		} 
	}
	return 0;
}
