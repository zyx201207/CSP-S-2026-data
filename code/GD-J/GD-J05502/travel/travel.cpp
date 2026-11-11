#include<bits/stdc++.h>
using namespace std;
int a1,a2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&a1);
	cin >> s1;
	scanf("%d",&a2);
	cin >> s2;
	if(a1!=a2) printf("0000");
	else
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			printf("11");
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
			{
				printf("1");
				if(abs(s1[2]-s2[2])==1) printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else
		{
			printf("1000");
		}
	}
	return 0;
}
