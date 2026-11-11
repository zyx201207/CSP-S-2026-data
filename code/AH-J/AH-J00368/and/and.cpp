#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
unsigned long long a[N],ans,cnt,ma=-1;
void d(int x,int pos,unsigned long long cur)
{
	if(pos==m){
		ans=max(ans,cur);
		if(ans==ma)
		{
			cout<<ans<<" ";
			exit(0);
		}
		return ;
	}
	int i;
	for(i=x+1;i<=n;i++)
		d(i,pos+1,cur&a[i]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)
			cnt=a[i];
		cnt&=a[i];
		ma=max(ma,a[i]);
	}
	if(m==n)
	{
		cout<<cnt;
		exit(0);
	}
	if(n==1)
	{
		cout<<ma;
		exit(0);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n-m+1;i++)
		d(i,1,a[i]);
	cout<<ans;
}
//Trick||Treat!
