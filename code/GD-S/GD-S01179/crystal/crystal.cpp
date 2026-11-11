#include<iostream>
#include<algorithm>


using i64=long long;

constexpr int maxn=5e5+7;

i64 A[maxn];

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int N;i64 M;std::cin>>N>>M;
	for(int i=0;i<N;i++) std::cin>>A[i];

	std::sort(A,A+N);
	int ans=1,l=0;
	i64 sum=0;
	for(int r=1;r<N;r++)
	{
		sum+=(A[r]-A[r-1])*(r-l);
		while(l<r&&sum>M){
			sum-=A[r]-A[l];
			l++;
		}
		ans=std::max(ans,r-l+1);
	}
	
	printf("%d",ans);
	
	return 0;
}
