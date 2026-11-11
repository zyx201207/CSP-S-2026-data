#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1e2,inf=2e9;
int c,T,n,d,a[N];
struct sb
{
	int w,num;
}f[N],t[N<<2];
sb add(sb x,sb y)
{
	if(x.w>y.w) return y;
	else if(x.w==y.w) return (sb){x.w,x.num+y.num};
	else return x;
}
void change(int p,int l,int r,int x,sb k)
{
	if(l==r){t[p]=k; return;}
	int mid=l+r>>1;
	if(x<=mid) change(p<<1,l,mid,x,k);
	else change(p<<1|1,mid+1,r,x,k);
	t[p]=add(t[p<<1],t[p<<1|1]);
}
sb ask(int p,int l,int r,int x,int y)
{
	if(x>y) return (sb){0,1};
	if(x<=l&&r<=y) return t[p];
	int mid=l+r>>1;
	sb val=(sb){inf,0};
	if(x<=mid) val=add(val,ask(p<<1,l,mid,x,y));
	if(y>mid) val=add(val,ask(p<<1|1,mid+1,r,x,y));
	return val;
}
void clear(int p,int l,int r)
{
	t[p]=(sb){inf,0};
	if(l==r) return;
	int mid=l+r>>1;
	clear(p<<1,l,mid);
	clear(p<<1|1,mid+1,r);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			f[i]=(sb){0,1};
			change(1,1,n,i,f[i]);
			for(int j=i+1;j<=n;j++)
			{
				int p=lower_bound(a+i,a+n+1,a[j]-d)-a;
				f[j]=ask(1,1,n,p,j-1); f[j].w++;
				if(f[j].num==2) ans++;
				change(1,1,n,j,f[j]);
			}
			clear(1,1,n);
		}
		cout<<ans<<'\n';
	}
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6