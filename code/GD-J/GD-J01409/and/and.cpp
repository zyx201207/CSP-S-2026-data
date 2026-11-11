#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,m,a[200005],maxn=0;
bool vis[200005];
void dfs(int sum,int k)
{
	if(k==m){
		maxn=sum>maxn?sum:maxn;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(sum&a[i],k+1);
		vis[i]=0;
	}
	
	return ;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(m==n){
		maxn=a[1];
		for(int i=1;i<=n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				maxn=a[i]&a[j]>maxn?a[i]&a[j]:maxn;
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		int minn=pow(2,32)-1;
		for(int i=1;i<=n;i++) minn=a[i]<minn?a[i]:minn;
		bool v=0,vv=0;
		int kk=a[4];
		
		for(int i=1;i<=n;i++){
			if(a[i]==minn&&v==0){
				v=1;
				continue;
			}
			kk&=a[i];
		}
		maxn=kk;
		cout<<maxn;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=a[i]>maxn?a[i]:maxn;
		}
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(a[i],1);
		vis[i]=0;
	}
	cout<<maxn;
	return 0;
}

