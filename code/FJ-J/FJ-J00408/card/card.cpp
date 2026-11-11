#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	vector<int> ans(m);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		//cout<<"第 "<<i<<" 局："<<endl;
		vector<int> table;
		for(int j=i;j<n;j++)
		{
			int k=a[j];
			bool has=0;
			int sz=table.size();
			for(int ii=0;ii<sz;ii++)
			{
				if(table[ii]==k)
				{
					has=1;
					break;
				}
			}
			if(has)
			{
				while(table[table.size()-1]!=k)
				{
					//cout<<"弹出"<<table[table.size()-1]<<endl; 
					table.pop_back();
				}
				//cout<<"弹出"<<table[table.size()-1]<<endl; 
				table.pop_back();
			}
			//cout<<"压入"<<k<<endl;
			table.push_back(k);
		}
		int sz=table.size();
		vector<bool> res(n);
		for(int j=0;j<sz;j++)
		{
			res[table[j]-1]=1;
		}
		for(int j=0;j<m;j++)
		{
			if(res[j])
			{
				ans[j]++;
			}
		}
		//cout<<"第 "<<i<<" 局结束，桌面：";
		for(int j=0;j<sz;j++)
		{
			//cout<<table[j]<<' ';
		}
		//cout<<endl;
	}
	for(int i=0;i<m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
