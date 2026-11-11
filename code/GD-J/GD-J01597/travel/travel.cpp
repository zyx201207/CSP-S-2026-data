#include<bits/stdc++.h>
using namespace std;
array<int,3> gt(string c,string s)
{
	int cx=(c[0]-'0')*10+(c[1]-'0');
	int ll=(s[0]-'0')*10+(s[1]-'0');
	int pp=s[2]-'A'+1;
	if(pp==4) pp++;
	return {cx,ll,pp};
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s;
	cin>>c>>s;
	array<int,3> a1=gt(c,s);
	cin>>c>>s;
	array<int,3> a2=gt(c,s);
	if(a1[0]!=a2[0]) printf("0000");
	else if(a1[1]!=a2[1]) printf("1000");
	else
	{
		if((a1[2]<=3&&a2[2]>3)||(a1[2]>3&&a2[2]<=3)) printf("1100");
		else if(abs(a1[2]-a2[2])!=1) printf("1110");
		else printf("1111");
	}
}
