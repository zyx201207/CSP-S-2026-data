#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn],board[maxn],head;
int sum[maxn];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		head=0;
		for(int j=i;j<=n;j++)
		{
			int pos=find(board,board+head,a[j])-board;
			if(pos<head)
				head=pos;
			board[head++]=a[j];
		}
		for(int j=1;j<=m;j++)
		{
			int pos=find(board,board+head,j)-board;
			if(pos<head)
				sum[j]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<" ";
	cout<<endl;
	return 0;
}
