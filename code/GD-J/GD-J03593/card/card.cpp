#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6;
int n,m;
int arr[N];
vector<int>vect[N];//存i-n情况下的数字 
int tmp[N];//存第i个位置的下个一个相同位
int ans[N];
map<int,int>mp; 
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>arr[i];
	for(int i=n;i>=1;i--)
	{
		if(mp[arr[i]])
		{
			tmp[i]=mp[arr[i]];
		}
		mp[arr[i]]=i;
	}
	for(int i=n;i>=1;i--)
	{
		if(tmp[i]!=0)
			vect[i]=vect[tmp[i]];
		else 
		{
			vect[i]=vect[i+1];
			vect[i].push_back(arr[i]);
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(auto t:vect[i])
			ans[t]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
