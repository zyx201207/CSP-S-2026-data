#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,ans,head,tail;
long long m;
long long a[N],q[N],num=0;
bool cmp(int x,int y)
{
	return (x+=(tail-head+1)*(y-q[tail])) > m;
}
int main()
{
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	q[1]=a[1];
	head=1,tail=1,ans=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>q[tail])
		{
			while(cmp(num,a[i]))
			{
				num-=q[tail]-a[head];
				head++;
			}
			num+=(tail-head+1)*(a[i]-q[tail]);
			tail++;
			q[tail]=a[i];
		}
		else
		{
			tail++;
			q[tail]=a[i];
		}
		ans=max(ans,tail-head+1);
	}
	cout<<ans;
	return 0;
}
