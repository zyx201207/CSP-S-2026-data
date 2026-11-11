#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 5e5 + 7;
const int M = 3e5 + 7;

int n,m;

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	vector<int> a(N);
	vector<int> ans(M);
	vector<int> id(M);
	set<int> num;
	vector<int> vis(M);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		id[a[i]] = i;
	}
//	for(int i = 1;i<=m;i++)
//	{
//		cout<<id[i]<<" ";
//	}
//	
//	cout<<endl<<endl;
	for(int st = 1;st <= n;st ++)
	{
		for(int i=st;i<=n;i++)
	    {
	    	if(id[a[i]]!=i)
			{
				i = id[a[i]];
				ans[a[i]]++;
			}
			else
			{
				ans[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
/*
4 3
1 2 1 3

//3 1 4

10 3
3 1 2 1 3 2 3 1 2 1
*/
