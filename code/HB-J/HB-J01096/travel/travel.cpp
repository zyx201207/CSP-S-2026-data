#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2;
	string b1,b2,ans="0000";
	cin>>a1>>b1>>a2>>b2;// cin
	if(a1==a2)
	{
		ans[0]='1';//sametrain
		if(b1[0]==b2[0] and b1[1]==b2[1])
		{
			ans[1]='1';//samepai
		
			if((b1[2]=='A' or b1[2]=='B' or b1[2]=='C') and (b2[2]=='A' or b2[2]=='B' or b2[2]=='C'))
				ans[2]='1';
			if((b1[2]=='F' or b1[2]=='D') and (b2[2]=='F' or b2[2]=='D'))
				ans[2]='1';//samece
		
			else if((b1[2]=='A' and b2[2]=='B') or (b1[2]=='B' and b2[2]=='C') or (b1[2]=='F' and b2[2]=='D'))
				ans[3]='1';
			else if((b1[2]=='B' and b2[2]=='A') or (b1[2]=='C' and b2[2]=='B') or (b1[2]=='D' and b2[2]=='F'))
				ans[3]='1';
		}

	}
		

	cout<<ans;
	return 0;
}
