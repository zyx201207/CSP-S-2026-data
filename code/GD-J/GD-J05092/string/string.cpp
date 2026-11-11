#include<bits/stdc++.h> 
using namespace std;
vector<pair<int,char> >v;
int n,k;
int num;
string s;
char x;
long long cnt;
bool vis[200007];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while (cin>>num>>x)
	{
		k++;
		v.push_back({num,x});
	}
	for (int i=0;i<=(k-1)/2;i++)
	{
		int c=v[i].first;
		if (v[i].second!=v[k-i-1].second && !vis[k-i-1])
		{
			vis[k-i-1]=1;
			cnt+=c;
		}
	}
	cout<<cnt;
	return 0;
}
