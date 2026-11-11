#include <bits/stdc++.h>
using namespace std;
int n,m;
bool f=true;
int a[200020],ans[200020];

int count(vector<int> b,int x)
{
	int res=0;
	for(int i=0;i<b.size();i++)
	{
		if(b[i]==x)
		{
			res++;
		}
	}
	return res;
}

int find(vector<int> b,int x)
{
	for(int i=0;i<b.size();i++)
	{
		if(b[i]==x)
		{
			return i;
		}
	}
}

int find2(vector<int> b,int x)
{
	int l=0,r=b.size()-1; 
	while(l<r)
	{
		int mid=l+(r-l)/2;
		if(mid==x)
		{
			return mid;
		}
		if(b[mid]<x)
		{
			l=mid+1;
		}
		if(b[mid]>x)
		{
			r=mid-1;
		}
	}
	return l;
}
 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			f=false;
		}
	}
	for(int i=1;i<=n;i++)
	{
		vector <int> t;
		for(int j=i;j<=n;j++)
		{
			if(count(t,a[j]) and !f)
			{
				t.erase(t.begin()+find(t,a[j])+1,t.end());
			}
			else if(count(t,a[j]) and f)
			{
				t.erase(t.begin()+find2(t,a[j])+1,t.end());
			}
			else
			{
				t.push_back(a[j]);
			}
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=count(t,j);
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
} 
