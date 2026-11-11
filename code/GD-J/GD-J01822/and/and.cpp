#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn,sum;
bool vis[200005];
void dfs(int id,int sum){
	if(id==m){
		maxn=max(sum,maxn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(id+1,sum&a[i]);
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum=sum&a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	else if(m==n){
		cout<<sum;
		return 0;
	}
	else if(n<=20){
		maxn=0;
		dfs(0,0x3fffffff);
		cout<<maxn;
	}
	return 0;
}

