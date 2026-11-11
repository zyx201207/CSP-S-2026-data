#include <iostream>

using namespace std;
typedef long long ll;

string p1,s1,p2,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	cin>>p1>>s1>>p2>>s2;
	if(p1!=p2) return cout<<"0000",0;
	else
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			int k=(s1[2]>'C')+(s2[2]>'C');
			if(k==1) return cout<<"1100",0;
			else if(abs(s1[2]-s2[2])==1) return cout<<"1111",0; 
			else return cout<<"1110",0;
		}
		else return cout<<"1000",0;
	}
	return 0;
}
