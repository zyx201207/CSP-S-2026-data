#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans;
int a[2000010];
int b[2000010];
int left_erfen(int x)
{
	int l=1,r=n,mid,res;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid]<=x)
		{
			l=mid+1;
			res=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	return res;
}
int right_erfen(int x)
{
	int l=1,r=n,mid,res;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid]<x)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;			
			res=mid;
		}
	}
	return res;
}
int my_count(int l,int r)
{
	if(l>r) return 0;
	int kskbl=left_erfen(r)-right_erfen(l)+1;
	return kskbl;
}
bool check(int l,int r)
{
	int x=l,res=1,len=0;
//	cout<<l<<" "<<r<<":";
	b[++len]=l;
	while(x<=r)
	{
		if(a[x]+d<a[x+1])
		{
//			cout<<"out1\n";
			return false;
		}
		if(a[x]+d>=a[r])
		{
			break;
		}
		x=left_erfen(a[x]+d);
		b[++len]=x;
//		cout<<x<<" ";
	}
	b[++len]=r;
//	for(int i=1;i<=len;i++) cout<<b[i]<<" ";
//	cout<<'\n';
	for(int i=1;i<=len-2;i++)
	{
		res*=my_count(a[b[i+2]]-d,a[b[i]]+d);
//		cout<<my_count<<" ";
		if(res>2) return false;
	}
//	cout<<"\n";
	if(res==2) return true;
	return false;
}
void solve()
{
	ans=0;
	cin>>n>>d;	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(check(i,j))
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
