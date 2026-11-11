#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c1,c2,t1,t2;
char s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>c1>>t1>>s1>>c2>>t2>>s2;
	if(c1==c2)
	{
		if(t1==t2)
		{
			if(!((s1<='C')^(s2<='C')))
			{
				if((s1!='A'||s2!='C')&&(s1!='C'||s2!='A')) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
}

