#include<iostream>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
	{
		cout << 1;
		string a=s1.substr(0,2),b=s2.substr(0,2);
		if(a==b)
		{
			cout << 1;
			int p=s1[2]-'A'+1,q=s2[2]-'A'+1;
			bool f1=0,f2=0;
			if(p>3) f1 = 1;
			if(q>3) f2 = 1;
			if(f1 == f2)
			{
				cout << 1;
				if(p+1 == q||q+1==p) cout << 1;
				else cout << 0;
			}
			else cout <<"00";
		}
		else cout <<"000";
	}
	else cout <<"0000";
	
	return 0;
}
