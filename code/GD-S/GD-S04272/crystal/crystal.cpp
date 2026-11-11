#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
long long n,m,ans=-1,cnt=0,sum=0,st=0;
const long long N=5e5+10;
vector<long long> a(N,0);
queue<long long> q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.begin()+n+1);
	for(long long i=1;i<n;i++)
	{
		long long sp=a[i+1]-a[i];
		cnt++;
		sum+=cnt*sp,st+=sp;
		q.push(sp);
		while(!q.empty()&&sum>m)
		{
			cnt--;
			sum-=st;
			st-=q.front();
			q.pop();
		}
		ans=max(ans,cnt);
	}
	cout<<ans+1;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
