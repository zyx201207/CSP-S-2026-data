#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int e,f;
	cin>>a>>b>>c>>d;
	if(a!=c) printf("0000");
	else
	{
		if((int)(b[0]-'0')*10+(int)(b[1]-'0')!=(int)(d[0]-'0')*10+(int)(d[1]-'0')) printf("1000");
		else
		{
			e=(int)(b[2]-'A')+1;
			f=(int)(d[2]-'A')+1;
			if(e<=3&&f>3||e>3&&f<=3) printf("1100");
			else
			{
				if(e==1&&f==3||e==3&&f==1) printf("1110");
				else printf("1111");
			}
		}
	}
	return 0;
}
