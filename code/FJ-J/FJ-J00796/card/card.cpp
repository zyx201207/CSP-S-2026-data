#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], cnt[300005], ans[300005];
void game(int num)
{
	vector<int> v;
	int i=1, len=0;
//	cout<<111<<endl;
	while(i<=num-1) 
	{
		i++;
	}
//	cout<<222<<endl;
	for(int j=1; j<=m; j++)
	{
		cnt[j]=0;
	}
	for(; i<=n; i++)
	{
		if(cnt[a[i]]==1)
		{
//			cout<<333<<endl;
			while(v[len-1]!=a[i])
			{
				cnt[v[len-1]]--;
				v.pop_back();
				len--;
			}
//			cout<<444<<endl;
			cnt[v[len-1]]--;
			len--;
			v.pop_back();
		}
		v.push_back(a[i]);
		cnt[a[i]]++;
		len++;
	}
	for(int i=0; i<len; i++)
	{
		ans[v[i]]++;
	}
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)
	{
		game(i);
	}
	for(int i=1; i<=m; i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
//Trick||Treat!Trick||Treat!Trick||Treat!

