//csp RP++
#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005],out=0,minn=1e18,maxn=0;
bool vis[200005];
void dfs(long long k,long long jg){
	if(k>m){
		cout<<jg;
		out=max(out,jg);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(k+1,jg&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(a[i],minn);
		maxn=max(a[i],maxn);
	}
	sort(a+1,a+n+1) 
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		out=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				out=max((a[i]&a[j]),out);
			}
		}
		cout<<out;
		return 0;
	}
	if(m==n){
		out=a[1];
		for(int j=2;j<=n;j++){
			out&=a[j];
		}
		cout<<out;
		return 0;
	}
	if(m==n-1){
		for(int j=2;j<=n;j++){
			out=a[1];
			for(int j=1;j<=n;j++){
				if(j!=i){
					out&=a[j];
				}
			}
		}
		cout<<out;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(1,a[i])
	}
	cout<<out;
	return 0;
} 
