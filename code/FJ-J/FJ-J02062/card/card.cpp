#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int cnt[N],a[N];
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(x!=q.top())
		q.push(x);
	}
	int l=q.size();
	for(int i=l;i>=1;i--)
	{
		a[i]=q.top();
		q.pop();
	}
	for(int i=1;i<=n;i++)
	{
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	cout<<cnt[i]<<' ';
	return 0;
} 
