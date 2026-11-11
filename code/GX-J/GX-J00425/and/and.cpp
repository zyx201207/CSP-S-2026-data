#include <bits/stdc++.h>
#define LL long long
#define AC return 0
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
inline void LI()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=min(m+i,n);j++)
		{
			int cnt=a[i];
			for(int k=i;k<=j;k++)
				cnt&=a[k];
			ans=max(ans,cnt);
		}
	cout<<ans;		
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int t=1;
//  cin>>t;
	while(t--)
		LI();
	AC;//rp+=INF
}
