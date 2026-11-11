#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1,a2,a3,a4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdot);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			a2=1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))
			{
				a3=1;
				if(abs(s1[2]-s2[2])==1)
				{
					a4=1;
				}
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
