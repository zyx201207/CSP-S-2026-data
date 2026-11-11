#include<bits/stdc++.h>
using namespace std;
char s1[3],s2[3],c1[2],c2[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]+c1[1]+c1[2]==c2[0]+c2[1]+c2[2])
	{
		cout<<1;
		if(s1[0]+s1[1]==s2[1]+s2[0])
		{
			cout<<1;
			if((s1[2]!='C'&&s2[2]!='D')&&(s1[2]!='D'&&s2[2]!='C'))
			{
				if(abs((s1[2]-'A')-(s2[2]-'A'))<=2)
				{
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0;
		}
	}else{
		cout<<0<<0<<0;
	}
	if((abs(s1[2]-s2[2])==1&&(s1[2]!='C'&&s2[2]!='D')&&(s1[2]!='D'&&s2[2]!='C')&&s1[1]==s2[1])||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))
	{
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
