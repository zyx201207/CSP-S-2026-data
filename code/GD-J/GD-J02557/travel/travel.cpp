#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,ans=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+=1000;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			ans+=100;
			if(('D'<=s1[2]&&'D'<=s2[2])||(s1[2]<='C'&&s2[2]<='C'))
			{
				ans+=11;
				if(s1[2]+s2[2]=='A'+'C')
					ans-=1;
			}
		}
	}
	if(ans==0)
		cout<<"0000"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
