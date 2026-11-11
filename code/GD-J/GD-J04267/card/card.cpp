#include<bits/stdc++.h>
using namespace std;

vector<int> cards;
vector<bool> mark;
vector<int> ans;
int n,m;

vector<int> play(int t)
{
	for(int i=t;i<n;i++)
	{
		for(int j=t;j<i;j++)
		{
			if(cards[j]==cards[i] && mark[j])
			{
				for(;mark[j] && j<i;j++)
					mark[j]=0;
				break;
			}
		}
		mark[i]=1;
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	int card;
	for(int i=0;i<n;i++)
	{
		cin>>card;
		cards.push_back(card);
		mark.push_back(0);
	}
	
	for(int i=0;i<m;i++)
		ans.push_back(0);
	
	for(int i=0;i<n;i++)
	{
		play(i);
		for(int j=i;j<n;j++)
			if(mark[j]) ans[cards[j]-1]++;
		for(int j=0;j<n;j++)
			mark[i]=0;
	}
	
	for(int i=0;i<m;i++) cout<<ans[i]<<' ';
	
} 
