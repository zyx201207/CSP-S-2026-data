#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
string c1,s1,c2,s2;
struct edge{
	string seatn;
	char seata;
	bool zy;
};
bool ans[10]={1};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	edge r,x;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else{
		ans[1]=1;
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]>='0' and s1[i]<='9')
			{
				r.seatn+=s1[i];
			}
			else{
				r.seata=s1[i];
				if(s1[i]=='A' or s1[i]=='B' or s1[i]=='C')
				{
					r.zy=0;
				}
				else{
					r.zy=1;
				}
			}
		}
		for(int i=0;i<s2.size();i++)
		{
			if(s2[i]>='0' and s2[i]<='9')
			{
				x.seatn+=s2[i];
			}
			else{
				x.seata=s2[i];
				if(s2[i]=='A' or s2[i]=='B' or s2[i]=='C')
				{
					x.zy=0;
				}
				else{
					x.zy=1;
				}
			}
			}
			if(r.seatn==x.seatn) ans[2]=1;
			if(r.zy==x.zy)
			{
			ans[3]=1;
			if(abs(r.seata-x.seata)==1)
			{
				ans[4]=1;
			}
			}
			for(int i=1;i<=4;i++)
			{
				if(ans[i-1]==0) ans[i]=0;
				cout<<ans[i];
			}
		}
	return 0;
}
