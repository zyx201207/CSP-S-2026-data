#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
bool vis[200005];
struct node{
	int a,b;
}a[200005];
bool cmp(node a,node b){
	if(a.b!=b.b) return a.b<b.b;
	return a.a<b.a;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
    for(int i=1;i<=n;i++)
	{
		cin>>a[i].a;
		if(a[i].a==0)
		{
			a[i].b=0;
			continue;
		} 
		int l=0,r=32;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(a[i].a>>mid) l=mid;
			else r=mid;
		}
		a[i].b=l;
	} 
	sort(a+1,a+1+n,cmp);
	for(int i=30;i>=0;i--)
	{
		int sum=0,cnt=m;
		bool f=0;
		for(int j=1;j<=n;j++) vis[j]=0;
		for(int j=n;j>=1&&cnt;j--)
		{
			if(a[j].b==i&&f==0)
			{
				f=1,sum=a[j].a;
				cnt--,vis[j]=1;
			} 
			else if(a[j].b==i)
			{
				sum=(sum&a[j].a);
				cnt--,vis[j]=1;
			} 
		}
		if(cnt&&i!=0)
		{
			for(int j=n;j>=1&&cnt;j--)
			{
				if(!vis[j]) sum=(sum&a[j].a),cnt--;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}

