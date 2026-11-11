#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int sum=0;
map<int,vector<pair<int,int> > > mp;
string s1;
int lh = 0,rh = 0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		char c;
		cin>>c;
		sum+=x;
		mp[c].push_back({x,sum});
	}
	if(sum&1)
	{
		lh = sum/2;
		rh = sum/2+1;
	}else{
		lh = sum/2;
		rh = sum/2;
	}
	for(int i='a';i<='z';i++)
	{
		for(int j=0;j<mp[i].size();j++)
		{	
			if(mp[i][j].second>rh && j>0 && mp[i][j-1].second<lh ){
				
				if(mp[i][j].first < mp[i][j-1].first)
				{
					mp[i][j-1].first -= mp[i][j].first;
					sum-=mp[i][j].first;
					mp[i][j].first=0;
				}else{
					mp[i][j].first -= mp[i][j-1].first;
					sum-=mp[i][j-1].first;
					mp[i][j-1].first=0;
				}
			}
		}
	}
	cout<<sum-rh;
}
	
 	
  	