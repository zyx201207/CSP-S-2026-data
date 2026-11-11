#include<bits/stdc++.h>
using namespace std;
int sp[100];
int M[100][100];
bool N[100000];
vector<int> S;
int c,n,m,d,q;
bool vised[100];
struct train
{
	bool K[100];
	vector<pair<int,int> > V[100];
}T[100];
//int findway(int from,int to)
//{
//	
//}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++)
	{
		cin>>sp[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin>>k;
		for(int i = 1;i <= k;i++)
		{
			int a,t;
			cin>>a>>t;
			if(N[a])
			{
				S.push_back(a);
			}
			else
			{
				N[a] = true;
			}
			T[i].V.push_back{a,t};
			T[i].K[a] = true;
		}
	}
	for(vector<int>::iterator it = T.begin(),it != T.end();it++)
	{
		for(int i = 1;i <= n;i++)
		{
			if(T[i].K[*it])
			{
				for(vector<pair<int,int>>::iterator it2 = T[i].V.begin();it2 != T[i].V.end();it2++)
				{
					M[*it][*it2] = it2->second;
					M[*it2][*it] = it2->second;
				}
			}
		}
	}
//	for(int i = 1;i <= q;i++)
//	{
//		int from,to;
//		cin>>from>>to;
//		cout<<findway(from,to)<<endl;
//	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 2;j <= n;j++)
		{
			for(vector<pair<int,int>>::iterator it1 = T[i].V.begin();it1 != T[i].V.end();it1++)
			{
				for(vector<pair<int,int>>::iterator it2 = T[j].V.begin();it2 != T[i].V.end();it2++)
				{
					M[it1->first][it2->forst] = it1->second + it2->second;
				}
			}
		}
	}
	for(int i = 1;i <= q;i++)
	{
		int from,to;
		cin>>form>>to;
		cout<<M[from][to]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
