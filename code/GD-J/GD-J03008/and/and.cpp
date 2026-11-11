#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<bitset<40>,long long>&a,pair<bitset<40>,long long>&b)
{
	return a.second>b.second;
}
const int N=2*1e5;
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<pair<bitset<40>,long long>>vec(N+10);
	vector<bool>choose(N+10);
	int chosed=0;
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		long long temp;
		cin>>temp;
		vec[i].first=bitset<40>(temp);
		vec[i].second=temp;
	}
	sort(vec.begin()+1,vec.end()-1,cmp);
	for(int i=39;i>=0&&!flag;i--)
	{
		for(int j=1;j<=n&&!flag;j++)
		{
			for(int k=j+1;k<=n&&!flag;k++)
			{
				if((vec[j].first[i]==vec[k].first[i])&&(vec[j].first[i]==1))
				{
					if(choose[j]&&choose[k]) break;
					if(chosed==m) flag=1;
					if(!choose[j]&&!flag)
					{
						choose[j]=1;
						chosed++;
					}
					if(chosed==m) flag=1;
					if(!choose[k]&&!flag)
					{
						choose[k]=1;
						chosed++;
					}
					break;
				}
			}
		}
	}
	long long ans=0;
	bool temp=0;
	for(int i=1;i<=n;i++)
	{
		if(choose[i])
		{
			if(!temp)
			{
				ans=vec[i].second;
				temp=1;
			}
			else ans&=vec[i].second;
		}
	}
	cout<<ans;
	return 0;
 } 
