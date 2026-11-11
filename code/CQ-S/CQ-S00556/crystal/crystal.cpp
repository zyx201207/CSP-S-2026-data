#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],ans,bit[N];
void update(int pos,int val)
{
	for(int i=pos;i<N;i+=lowbit(i))
		bit[i]+=val;
}
int sum(int pos)
{
	int tot=0;
	for(int i=pos;i;i-=lowbit(i))
		tot+=bit[i];
	return tot;
}
int query(int l,int r)
{
	if(r==n)
		return (a[n]-a[n-1])*(r-l)+query(l,r-1);	
	r--;
	return sum(r)-sum(l-1)-(r-l+1)*b[r+1];
}
void solve(int x)
{
	int l=1,r=x,pos=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(query(mid,x)<=m)
			r=mid-1,pos=mid;
		else
			l=mid+1;
	}
	ans=max(ans,x-pos+1);
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--)
		b[i]=a[i+1]-a[i];
	for(int i=n;i>=1;i--)
		b[i]+=b[i+1];
	b[n]=b[n-1];	
	for(int i=1;i<=n;i++)
		update(i,b[i]);
	for(int i=1;i<=n;i++)
		solve(i);
	cout<<ans;
    return 0;
}
