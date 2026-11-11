#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[501000],lst[300100],m,cnt,q[500100],ans[300100];
struct node{
	ll l,r;
	bool operator < (const node &y)const{
		return l<y.l;
	}
}edge[500100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(lst[a[i]])edge[++cnt]=node{lst[a[i]],i-1};
		lst[a[i]]=i;
	}
	sort(edge+1,edge+cnt+1);
	int tot=cnt;
	for(int i=n;i;i--)
	{
		q[i]++;
		while(cnt&&edge[cnt].l>=i)
		{
			if(cnt+1<=tot&&edge[cnt].r>=edge[cnt+1].l)q[edge[cnt].l]--,q[edge[cnt+1].l]++;
			else q[edge[cnt].l]--,q[edge[cnt].r+1]++;
			cnt--;
		}
		cnt=tot;
	}
	for(int i=1;i<=n;i++)q[i]+=q[i-1],ans[a[i]]+=q[i];
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}