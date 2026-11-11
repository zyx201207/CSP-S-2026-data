#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
vector<int> v;
void jzg(vector<int> &v)
{
	int l=v.size();
	for(int i=0;i<l;i++)
	{
		if(v[i]==v[l])
		{
			for(int j=i+1;j<=l;j++) v.erase(v.end());
			break;
		}
		
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int n1=n;//n1 当前局数 
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n1;i++)
	{
		
		for(int j=i;j<n1;j++)
		{
			v.push_back(a[j]);
			jzg(v);
		}
		for(int k=0;k<v.size();k++)
		{
			b[v[k]]++;
		}
	}
	for(int i=1;i<=m;i++)
	cout<<b[i]+m-1<<" ";
}
