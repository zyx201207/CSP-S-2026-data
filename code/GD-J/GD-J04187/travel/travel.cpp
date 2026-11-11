#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1, s1, c2, s2;
	vector <int> ans(4,0);
	cin>>c1>>s1>>c2>>s2;
	for (int i=0;i<=1;i++)
	{
		if(c1[i]==c2[i] && c1[i+1]==c2[i+1])
		{
			ans[0]=1;
		}
		else
		{
			ans[0]=0;
		}
	}
	for (int i=1;i<s1.size()-1;i++)
	{
		if (s1[i-1]==s2[i-1] and s1[i]==s2[i])
		{
			ans[1]=1;
			break;
		}
		else
		{
			ans[1]=0;
			break;
		}
	}
	for (int i=2;i<=s1.size()-1;i++)
	{
		char w1=s1[i],w2=s2[i];
		if ((int(w1)>=65 && int(w1)<=67) && (int(w2)>=65 && int(w2)<=67))
		{
			ans[2]=1;
			break;
		}
		if ((int(w1)>=68 && int(w1)<=70) && (int(w2)>=68 && int(w2)<=70))
		{
			ans[2]=1;
			break;
		}
		else
		{
			ans[2]=0;
			break;
		}
	}
	for (int i=2;i<=s1.size()-1;i++)
	{
		char w1=s1[i],w2=s2[i];
		if ((int(w1)>=65 && int(w1)<=67) && (int(w2)>=65 && int(w2)<=67))
		{
			if ((int(w1)==65 && int(w2)==66) || (int(w1)==66 && int(w2)==67))
			{
				ans[3]=1;
				break;
			}
			else
			{
				ans[3]=0;
			}
		}
		if ((int(w1)>=68 && int(w1)<=70) && (int(w2)>=68 && int(w2)<=70))
		{
			ans[3]=1;
			break;
		}
	}
	for (int i=0;i<4;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
