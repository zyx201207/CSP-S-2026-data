//GZ-S00121 遵义市南白中学 卢杰子豪 

#include<fstream>
#include<vector>

std::ofstream out("migrate.out");
std::ifstream in("migrate.in");

using ll=long long;
using ull = unsigned long long;
int main()
{
	int c,t;
	in>>c>>t;
	while(t--)
	{
		int n;
		ull d;
		in>>n>>d;
		std::vector<ll> x(n+1);
		std::vector<ull> min(n+1,1);
		std::vector<ull> premin(n+1,0);
		for(int i=1;i<=n;i++)in>>x[i];
		int l=1,r=1,cl=1;
		ull cnt=0;
		premin[1]=1;
		while(r<n)
		{
			r++;
			int oldl=l;
			while(x[r]-x[l]>d)++l;
			while(x[l]-x[cl]>d)++cl;
			if(r-l==2)
			cnt+=(premin[l-1]+premin[cl-1]-premin[oldl-1]-premin[oldl-1]);
			min[r]+=premin[r-1]-premin[l-1];
			premin[r]=premin[r-1]+min[r];
		}
		out<<cnt<<'\n';
	}
	return 0;
}
