#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[500005];
vector<int> pl(vector<int> c)
{
	vector<int> now;
	for(int i=0;i<c.size();i++)
	{
		for(int j=0;j<now.size();j++)
		{
			if(c[i]==now[j])
			{
//				cout<<c[i]<<" "<<i<<endl;
				for(int k=j;k<now.size();k++)now.erase(now.begin()+k);
//				break;
			}
		}
		now.emplace_back(c[i]);
	}
	return now;
} 
int cnt[300005],out[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		vector<int> nowc;
		for(int j=i;j<=n;j++)nowc.emplace_back(c[j]);
//		cout<<i<<endl;
//		for(auto i:nowc)cout<<i<<" ";
//		cout<<endl;
		vector<int> f=pl(nowc);
		for(auto i:f)cnt[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(out[c[i]])continue;
		cout<<cnt[c[i]]<<" ";
		out[c[i]]=1;
	}
	cout<<endl;
	return 0;
}
/*
T4 card eps/100
11:30~12:00
暴力都打爆了。
怎么办。
最后一战？ 
*/
