#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long r=1,l=1,now=0; r<=n; r++)
	{
		now+=(r-l)*(a[r]-a[r-1]);
		//printf("r now is %d,now is %d\n",r,now);
		while(now>m)
		{
			now-=a[r]-a[l];
			l++;
			//printf("l now is %d,now now is %d\n",l,now);
		}
		ans=max(r-l+1,ans);
		//printf("End l is %d,End now is %d\n\n",l,now);
	}
	cout<<ans;
	
	return 0;
} 
//T1 双指针 20min 直接秒掉，其他人大概还在打 DFS（偷笑 
