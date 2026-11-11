#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int N=2e6+5;
#define int long long
int x[N];
int n,d;
struct node
{
	int l,r;
};
vector<node> ans;
vector<node> vec;
void solveA()
{
	if(x[2]-x[1]<=d&&x[3]-x[1]>=d)
		cout<<n-3<<"\n";
	else
		cout<<0<<"\n";
	return;
}
bool checkd()
{
	int c=x[2]-x[1];
	for(int i=3;i<n;i++)
	{
		if(x[i]-x[i-1]!=c)return false;
	} 
	return true;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migtate.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		vec.clear();
		cin>>n>>d;
		if(n<4)
		{
			cout<<0<<"\n";
			continue;
		}
		int lst=1;
		cin>>x[1];
		for(int i=2;i<=n;i++)
		{
			cin>>x[i];
			if(x[i]-x[i-1]>d)
			{
				vec.push_back({lst,i-1});
				lst=i;
			}
		}
		vec.push_back({lst,n});
		if(checkd())
		{
			solveA();
			continue;
		}
//		for(int i=0;i<vec.size();i++)
//		{
//			cout<<vec[i].l<<" "<<vec[i].r<<"\n";
//		}
//		cout<<"\n";
		int ans=0;
		for(int time=0;time<vec.size();time++)
		{
			int l=vec[time].l,r=vec[time].r;
			if(r-l<3)continue;
			for(int i=l;i<=r-3;i++)
			{
				if(x[i+3]-x[i]>d&&x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d)
				{
					int l=1,r=1;
					int ii=i;
					while(x[ii]-x[ii-1]<=d&&x[ii]-x[ii-2]>d)
					{
						ii--;
						l++;
					}
					ii=i+3;
					while(x[ii+1]-x[ii]<=d&&x[ii+2]-x[ii]>d)
					{
						ii++;
						r++; 
					}
					ans+=l*r;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
