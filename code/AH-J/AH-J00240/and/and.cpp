#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y[200005];
}vis[35];
int n,m,sum,cnt,a[200005],b[200005],ans[35],s[35];
void work(int x){
	int p=1,xx=x;
	for(; x>0; p++,x/=2)
		if(x%2)
			vis[p].y[++vis[p].x]=xx;
}
void dfs(int p){
	if(p==0) return;
	for(int i=1; i<=30; i++)
		vis[i].x=0;
	for(int i=1; i<=cnt; i++)
		work(b[i]);
	for(int i=p; i>=1; i--)
		if(vis[i].x>=m)
		{
			cnt=vis[i].x;
			for(int j=1; j<=vis[i].x; j++)
				b[j]=vis[i].y[j];
			dfs(i-1);
			ans[i]=1;
			break;
		}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; b[++cnt]=a[i],i++)
		cin>>a[i];
	dfs(30);
	s[1]=1;
	for(int i=2; i<=30; i++)
		s[i]=s[i-1]*2;
	for(int i=1; i<=30; i++)
		sum+=s[i]*ans[i];
	cout<<sum;
    return 0;
}
