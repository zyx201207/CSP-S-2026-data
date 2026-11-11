#include<bits/stdc++.h>
using namespace std;
string c1,c2;
int bool1[5]={ };
char s1[4],s2[4];
int main()
{

    freopen("travel5.in","r",stdin);
    freopen("travel5.out","w",stdout);
    cin>>c1;
    for(int i=1;i<=3;i++)
    {
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++)
    {
		cin>>s2[i];
	}



    if(c1==c2)
    {
		bool1[1]=1;
    }
    else
    {
        for(int i=1;i<=4;i++)
    {
		cout <<bool1[i];
	}
	return 0;
    }
	if(s1[2]==s2[2])
	{
		bool1[2]=1;
	}
	if(s1[2]==s2[2]&&((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')))
    {
        bool1[3]=1;
    }
    if(s1[2]==s2[2]&&((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')))
    {
        bool1[3]=1;
    }

    for(int i=1;i<=4;i++)
    {
		cout <<bool1[i];
	}
    return 0;
}
