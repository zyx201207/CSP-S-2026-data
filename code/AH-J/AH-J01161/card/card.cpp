#include<bits/stdc++.h>
using namespace std;
struct stu
{
	bool bj;
	int id;
};
stu b[300005];
int a[500005];
int t[300005];
vector<int>vec;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int c=1;c<=n;c++)
	{
		for(int i=c;i<=n;i++)
		{
			if(!b[a[i]].bj)
			{
				vec.push_back(a[i]);
				b[a[i]].bj=1;
				b[a[i]].id=vec.size();
			}
			else
			{
				for(int j=b[a[i]].id-1;j<vec.size();j++)
				{
					b[vec[j]].bj=0;
					b[vec[j]].id=0;
					vec.erase(vec.begin()+j);
					j--;
				}
				vec.push_back(a[i]);
				b[a[i]].bj=1;
				b[a[i]].id=vec.size();
			}
		}
		for(int i=0;i<vec.size();i++)
		{
			t[vec[i]]++;
		}
		vec.clear();
		for(int i=1;i<=m;i++)
		{
			b[i].bj=b[i].id=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
