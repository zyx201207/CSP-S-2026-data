#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
const int M=3e5+5;
int cnt[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		vector<int> q;
		int front=0;
		for(int j=1+(i-1);j<=n;++j)
		{
			int flag=-1;
			for(int k=q.size()-1;k>=front;k--)
			{
				if(a[j]==q[k])
				{
					flag=k;break;
				}
			}
			if(flag!=-1)
			{
				front=flag+1;
				//cout<<"***";
				q.push_back(a[j]);
			}
			else
			{
				q.push_back(a[j]);
			}
		}
		for(int j=front;j<q.size();++j)
		{
			cout<<q[j]<<" ";
			cnt[q[j]]++;
		}
		cout<<"front:"<<front<<endl;
	}
	for(int i=1;i<=m;++i)
	{
		cout<<cnt[i]<<" "; 
	}
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
