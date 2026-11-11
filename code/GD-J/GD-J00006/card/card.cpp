#include<bits/stdc++.h>
using namespace std;
const int N =5e5+5;
const int M=3e5+5;
int cnt[M],n,m,a[N];
deque<int> q;
int main()	{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int te=1;te<=n;te++)	{
		for(int i=te;i<=n;i++)	q.push_back(a[i]);
		for(int i=te;i<=n;i++)	{
			int now=-1;
			for(int j=0;j<q.size();j++)	{
				if(q[j]==a[i])	{
					now=q.size()-j;
					break;
				} 
			}
			if(now==-1)	q.push_back(a[i]);
			else {
				for(int j=1;j<=now;j++)	q.pop_back();
				q.push_back(a[i]);
			}
		}
		while(!q.empty())	{
			int x=q.front();
			q.pop_front();
			cnt[x]++;
		}	
	}
	for(int i=1;i<=m;i++){
		if(i==m)	cout<<cnt[i];
		else cout<<cnt[i]<<' ';
	}
	return 0;
}
/*
Trick||Treat!
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
