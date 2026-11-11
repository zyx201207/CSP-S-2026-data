#include<iostream>
using namespace std;

string t1, t2;
string s1, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w", stdout);
	cin>>t1>>s1>>t2>>s2;
	if (t1!=t2)
	{
		cout <<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
		if(s1[2]<='C'&& s2[2]<='C')
		{
			cout<<1;
			if(abs(s1[2]-s2[2])==1)cout<<1;
			else cout << 0;
		}else if(s1[2]>='D'&&s2[2]>='D')
		{
			cout<<11;
		}
	}
	else cout <<"000";
	
	
	
	return 0;
}
