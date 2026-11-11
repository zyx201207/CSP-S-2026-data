#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	int c1,c2,ans[4];
	string s1,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	
	if(c1==c2){
		ans[0]=1;
		if(s1[1]==s2[1]&&s1[0]==s2[0]){
			ans[1]=1;
			if(s2[2]<='C'&&s1[2]<='C'||s2[2]>='D'&&s1[2]>='D')
			{
				ans[2]=1;
				if(s1[2]-'A'+1==s2[2]-'A'||s1[2]-'A'-1==s2[2]-'A')ans[3]=1;
				else
				ans[3]=0;
		    }
		    else
		    {
			ans[2]=0;
			ans[3]=0;
			}
		}
		else
		{
		ans[2]=0;
        ans[3]=0;
        ans[1]=0;
		}
	}
	else
	{
		ans[2]=0;
        ans[3]=0;
        ans[1]=0;
        ans[0]=0;
	}
	for(int i=0;i<=3;i++){
		cout<<ans[i];
	}
	return 0;
}
