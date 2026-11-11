#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll R,X;
string r,x;
bool ans1=false,ans2=false,ans3=false,ans4=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld",&R);
	cin>>r;
	scanf("%lld",&X);
	cin>>x;
	if(R==X)
	{
		ans1=true;
		if(r[0]==x[0]&&r[1]==x[1])
		{
			ans2=true;
			if((r[2]>='A'&&r[2]<='C'&&x[2]>='A'&&x[2]<='C')||(r[2]>='D'&&r[2]<='F'&&x[2]>='D'&&x[2]<='F'))
			{
				ans3=true;
				if(abs(ll(r[2])-ll(x[2]))==1)
				{
					ans4=true;
				}
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
