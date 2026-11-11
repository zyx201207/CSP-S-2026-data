#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> vec(n);
	for(int &i:vec)cin>>i;
	if(n==m)
	{
		int a=vec[0];
		for(int i=0;i<n;i++)
		{
			a&=vec[i];
		}
		return 0;
	}
	if(m==1)
	{
		int a=-2e9;
		for(int i=0;i<n;i++)
			if(vec[i]>a)a=vec[i];
		cout<<a;
		return 0;
	}
	if(m==2)
	{
		int a=-2e9;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int k=vec[i]&vec[j];
				if(k>a)a=k;
			}
		}
		cout<<a;
	}
	return 0;
}