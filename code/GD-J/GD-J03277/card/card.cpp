#include<bits/stdc++.h>
using namespace std;
long long int n,m;
int a[500005];
vector<int> p;
bool Map[300005];
int c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=0;j<n;j++)
	{
		for(int i=1+j;i<=n;i++)
		{
			if(Map[a[i]]==0)
			{
				p.push_back(a[i]);
				Map[a[i]]=1;
				c[a[i]]+=1;
			}
			else
			{
				long long int t=p.size();
				while(p[t-1]!=a[i])
				{
					Map[p[t-1]]=0;
					c[p[t-1]]-=1;
					p.pop_back();
					t--;
				}
			}
			
		}
		p.clear();
		for(int i=1;i<=m;i++)
		{
			Map[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
