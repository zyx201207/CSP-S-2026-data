#include <bits/stdc++.h>
using namespace std;
string c1[2],s1[3],c2[2],s2[3];
int a,n,s,k;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1[2]>>s1[3]>>c2[2]>>s2[3];
	if (c1==c2)
	{
		a=1;
		if (s1[0]==s2[0]&&s1[1]==s2[1])
		{
			n=1;
			if (s1[2]<="C"&&s2[2]<="C")
			{
				s=1;
				if (s1[2]=="B" && s2[2]=="B")
					k=1;
			}
			else
			{
				s=1;
				k=1;
			}
		}
	}
	cout<<a<<n<<s<<k;
	return 0;
}
