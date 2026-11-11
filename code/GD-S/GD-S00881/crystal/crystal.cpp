#include <iostream>
#include <algorithm>
const int maxn=5e5+32;
const long long inf=1e18;
long long a[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	long long n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	std::sort(a+1,a+1+n);
	int ans=1;
	long long num=a[1];
	long long need=0;
	for(int i=2,j=1;i<=n;i++){//ÒÔiÎªÓÒ¶Ëµã 
		need+=(i-j)*(a[i]-num);
		while(j<i&&m<need){
			need-=(a[i]-a[j]);
			j++;
		}
		num=a[i];
		ans=std::max(ans,i-j+1);
	}
	std::cout<<ans;
	return 0;
}
