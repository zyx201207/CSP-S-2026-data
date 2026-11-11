#include<bits/stdc++.h>
#define int long long
#define prior priority_queue<int,vector<int>,greater<int>> 
#define N 2000010
using namespace std;
int n,d,c,T,deq[N],a[N],dp[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int q=0,p=0; //中继点最大值
//		while(a[++q]>d&&q<n);
		int l=q,r=n,mid;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(a[mid]<d) l=mid+1;
			else r=mid;
		}
		q=l,r=n;
		while(l<r) //终点最大值 
		{
//			cout<<1;
			mid=(l+r)>>1;
			if(a[mid]-a[q]<=d) l=mid+1;
			else r=mid;
		}
		p=l-1;
		
//		cout<<"--pq "<<p<<' '<<q<<endl;
		
		cout<<(p-q)*(q-1)<<endl;
	}
	return 0;
}
/*

找中间点？ 

*/
