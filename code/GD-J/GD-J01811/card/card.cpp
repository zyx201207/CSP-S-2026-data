#include <bits/stdc++.h>

using namespace std;
const int N=5e5+10;
const int M=3e5+10;

long long n,m;

long long a[N];
long long book[M];

long long nxt[N][25];
long long pre[N];
long long color[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{

		cin>>a[i];
	}

	for(int i=1;i<=n;i++)
	{

		pre[i]=color[a[i]];
		color[a[i]]=i;
		if(pre[i]==0)
		{

			continue;
		}
		nxt[pre[i]][0]=i;

	}
	nxt[0][0]=0;
	for(int j=1;j<=22;j++)
	{

		for(int i=1;i<=n;i++)
		{

			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
			//cout<<nxt[i][j-1]<<" "<<nxt[nxt[i][j-1]][j-1]<<endl;

		}
	}
	/*
	for(int i=1;i<=n;i++)
	{

		cout<<nxt[i][0]<<" ";

	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<nxt[nxt[i][0]][0]<<" "<<nxt[i][0]<<endl;
		//cout<<nxt[i][1]<<" ";
	}

	*/
	//cout<<endl;
	long long st;

	for(int i=1;i<=n;i++)
	{

		st=i;

		while(st<=n)
		{
			if(nxt[st][0]==0)
			{
				//cout<<a[st]<<" ";
				book[a[st]]++;

				st++;
			}
			else
			{

				for(int j=22;j>=0;j--)
				{

					if(nxt[st][j]!=0)
					{

						st=nxt[st][j];
					}
				}

				//st=nxt[st][0];
			}


		}
		//cout<<endl;
	}

	for(int i=1;i<=m;i++)
	{

		cout<<book[i]<<" ";
	}

	return 0;
}
