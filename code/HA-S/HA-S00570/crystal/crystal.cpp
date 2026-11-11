#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ms(A,b) memset
#define w while
using namespace std;
const int N=5e5+300;
int n;
ll m;
ll A[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>A[i];
	sort(A+1,A+n+1);
	int l=1;
	ll sum=0;
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(A[i]-A[i-1]>m)
		{
			l=i;
			sum=0;
			continue;
		}
		sum+=(A[i]-A[i-1])*(i-l);
		w(sum>m) sum-=(A[i]-A[l]),l++;
		ans=max(ans,i-l);
	}
	cout<<ans+1;
	return 0;
}
