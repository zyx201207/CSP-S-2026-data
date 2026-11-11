#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c[5],s[5];
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	int bo[5]={0};
	if(c[1]==c[2])
	{
		bo[1]=1;
		if(s[1][1]==s[2][1]&&s[1][2]==s[2][2])
		{
			bo[2]=1;
			if((s[1][3]>='D'&&s[1][3]<='F'&&s[2][3]>='D'&&s[2][3]<='F')||(s[1][3]>='A'&&s[1][3]<='C'&&s[2][3]>='A'&&s[2][3]<='C'))
			{
				bo[3]=1;
				if((s[1][3]==s[2][3]+1||s[1][3]==s[2][3]-1)&&min(s[1][3],s[2][3])!='C')
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<bo[i];
	}
	return 0;
}
