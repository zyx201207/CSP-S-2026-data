#include<bits/stdc++.h>//贵阳市花溪区剑桥中学  李政轩   GZ-S00290 
using namespace std;
const int maxn = 1e6+325;
long long c,t,n,d,sum;
long long x[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i = 1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j = 1;j<=n;j++)
		{
			cin>>x[j];
		}
		long long s = x[n]-x[1];
		long long step = (s+1)/d;
//		if(s<step*d)sum++;
		for(int j = 1;j<s;j++)
		{
			if(s-j<=(step-((j+1)/d))*d)sum++;
		}
		cout<<sum-1<<endl;
	}
	return 0;
}
