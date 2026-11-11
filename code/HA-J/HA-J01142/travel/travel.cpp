#include<bits/stdc++.h>
using namespace std;
struct Role{
	int xiang;
	string s;
}Node[5];
int ans[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++)
	{
		cin>>Node[i].xiang>>Node[i].s;
	}
	int wei1=(Node[1].s[0]+Node[1].s[1])-96;
	char letter1=Node[1].s[2];
	int wei2=(Node[2].s[0]+Node[2].s[1])-96;
	char letter2=Node[2].s[2];
	if(Node[1].xiang==Node[2].xiang)
	{
		ans[1]=1;
		if(wei1==wei2)
		{
			ans[2]=1;
			if((letter1<='C'&&letter2<='C') || (letter1>='D'&&letter2>='D'))
			{
				ans[3]=1;
				if(letter1-letter2==1 || letter2-letter1==1 )
				{
					ans[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
