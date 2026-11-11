#include<bits/stdc++.h>
using namespace std;
int n,m,c1,c2,d1,d2;
char s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>d1>>s1>>c2>>d2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(d1==d2)
		{
			cout<<1;
			if((s1<=67&&s2<=67) || (s1>=68&&s2>=68))
			{
				cout<<1;
				if(s1=='D'&&s2=='F') cout<<1;
				else if(s1=='F'&&s2=='D') cout<<1;
				else if(s1-s2==1||s2-s1==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
