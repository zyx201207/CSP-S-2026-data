#include<bits/stdc++.h>
using namespace std;
struct appeared
{
	int situation;
	bool isAppared;
};
vector<unsigned long long> last(vector<int> card,vector<appeared> app,int m)
{
	vector<unsigned long long> ans;
	for(int i=0;!card.empty();i++)
	{
		if(app[card[i]].isAppared==1)
		{
			for(unsigned long long j=app[card[i]].situation+1;j<card.size();j++)
			{
				ans.erase(ans.begin()+j);
			}
			app[card[i]].situation=i;
		}
		else
		{
			ans.push_back(card[i]);
			app[card[i]].situation=i;
		}
	}
	return ans;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	unsigned long long n,m;
	cin>>n>>m;
	vector<int> card(n);
	vector<appeared> app(m+1,{0,0});
	for(unsigned long long i=0;i<n;i++)
	{
		cin>>card[i];
	}
	for(unsigned long long i=0;i<n;i++)
	{
		vector<unsigned long long> las=last(card,app,m-i);
		card.erase(card.begin());
		int ans=0;
		for(unsigned long long j=0;j<las.size();j++)
		{
			if(las[j]==i+1)
			{
				ans++;
			}
		}
		cout<<ans<<' ';
	}
	return 0;
}
