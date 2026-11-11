#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool vis[200005];
int maxn=0;
void dfs(int fi,int ans){
	if(fi==m){
		if(ans>maxn){
			maxn=ans;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(fi==0){
				dfs(fi+1,a[i]);
			}
			else{
				dfs(fi+1,ans&a[i]);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(m==1){
		int q=-1,p;
		for(int i=1;i<=n;i++){
			cin>>p;
			if(p>q||q==-1){
				q=p;
			}
		}
		cout<<q;
		return 0;
	}
	else if(m==n){
		cin>>a[1];
		maxn=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			maxn=maxn&a[i];
		}
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<maxn;
	return 0;
}
