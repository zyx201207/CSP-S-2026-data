//GZ-S00121 遵义市南白中学 卢杰子豪 

#include<fstream>
#include<vector>
#include<algorithm>

std::ofstream out("crystal.out");
std::ifstream in("crystal.in");

using ull= unsigned long long;
using ll=long long;

int main()
{
	int n;
	ull m;
	in>>n>>m;
	std::vector<ll> a(n);
	for(auto& i:a)in>>i;
	std::sort(a.begin(),a.end());
	
	int max=1;
	int j=0;
	ull cost=0;
	
	for(int i=1;i<n;i++)
	{
		if(j==i)continue;
		cost+=(i-j)*(a[i]-a[i-1]);
		while(cost>m)cost-=(a[i]-a[j++]);
		if(i-j+1>max)max=i-j+1;
	}
	
	out<<max;
	return 0;
}
