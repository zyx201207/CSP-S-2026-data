#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;
#define cin lyc
#define cout lmy
ifstream cin("crystal.in");
ofstream cout("crystal.out");
long long a[500005];
long long m,sum;
int n,ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	int l=1;
	for(int r=1;r<=n;r++)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m)	sum-=(a[r]-a[l++]);
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
}