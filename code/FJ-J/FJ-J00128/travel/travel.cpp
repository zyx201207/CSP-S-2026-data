#include<bits/stdc++.h>
using namespace std;
struct trian
{
	string a,b,c,d;
}e;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>e.a>>e.b>>e.c>>e.d;
	if(e.a==e.c)
	{
		if(e.b[0]==e.d[0]&&e.b[1]==e.d[1])
		{
			if(((e.b[2]=='A'||e.b[2]=='B'||e.b[2]=='C')&&(e.d[2]=='A'||e.d[2]=='B'||e.d[2]=='C'))||((e.b[2]=='D'||e.b[2]=='F')&&(e.d[2]=='D'||e.d[2]=='F')))
			{
				if(e.b[2]+1==e.d[2]||e.b[2]-1==e.d[2]) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
}
