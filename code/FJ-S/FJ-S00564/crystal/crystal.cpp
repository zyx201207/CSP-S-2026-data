#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define int long long
int n,m,a[500006];
class node
{
public:
	int x,cnt=0;
}b[500006];int k=1,ans,tmp,max_n,s;
signed main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	b[k].x=a[1];b[k].cnt++;
	for(int i=2;i<=n;i++)
	{
		if(b[k].x==a[i])b[k].cnt++;
		else k++,b[k].x=a[i],b[k].cnt=1;
	}
	max_n=n;
	for(int i=k;i>=1;i--)
	{
		if(max_n<=ans||max_n<(n+1)/2)break;
		tmp=b[i].cnt;
		s=m;
		for(int j=i-1;j>=1;j--)
		{
			if(b[j].cnt*(b[i].x-b[j].x)<=s)
			{
				tmp+=b[j].cnt;
				s-=b[j].cnt*(b[i].x-b[j].x);
			}
			else
			{
				tmp+=(s/(b[i].x-b[j].x));
				break;
			}
		}
		ans=max(ans,tmp);
		max_n-=b[i].cnt;
	}
	cout<<ans;
}
