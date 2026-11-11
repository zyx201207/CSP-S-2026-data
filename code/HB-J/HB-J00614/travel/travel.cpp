#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int flag=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb)
	{
		flag++;
		int la=(sa[0]-48)*10+(sa[1]-48);
		int lb=(sb[0]-48)*10+(sb[1]-48);
		if(la==lb)
		{
			flag++;
			if(((sa[2]=='A'||sa[2]=='B'||sa[2]=='C')&&(sb[2]=='A'||sb[2]=='B'||sb[2]=='C'))||((sa[2]=='D'||sa[2]=='F')&&(sb[2]=='D'||sb[2]=='F')))
			{
				flag++;
				if((sa[2]=='A'&&sb[2]=='B')||(sa[2]=='B'&&sb[2]=='A')||(sa[2]=='C'&&sb[2]=='B')||(sa[2]=='B'&&sb[2]=='C')||(sa[2]=='D'&&sb[2]=='F')||(sa[2]=='F'&&sb[2]=='D'))
				{
					flag++;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		if(flag!=0) cout<<1,flag--;
		else cout<<0;
	}
	return 0;
}
