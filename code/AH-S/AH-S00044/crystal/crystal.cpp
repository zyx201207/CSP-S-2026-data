#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=1,ans=0;
	long long sum=0;
	while(r<=n)
	{
		r++;
		sum+=(r-l-1)*(a[r]-a[r-1]);
		while(sum>m)
			++l,sum-=a[r]-a[l];
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}
