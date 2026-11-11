#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
string s1,s2,t1,t2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1)
	{
		cout<<"1";
		string s;
		s+=s2[0];
		s+=s2[1];
		string t;
		t+=t2[0];
		t+=t2[1];
		if(s==t)
		{
			cout<<"1";
			if((s2[2]<='C'&&t2[2]<='C')||(s2[2]>='D'&&t2[2]>='D'))
			{
				cout<<"1";
				ll s3=s2[2]-'A';
				ll t3=t2[2]-'A';
				if(s3==t3+1||s3+1==t3) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
