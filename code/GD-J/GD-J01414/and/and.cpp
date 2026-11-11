#include <bits/stdc++.h>
using namespace std;
int a[100005]={ };
bool b[100005]={ };
int n,m;
int maxans=0;
void dfs(int k,int ans){
	if(k==0){
		maxans=max(maxans,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			dfs(k-1,ans&a[i]);
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=1;
		dfs(m-1,a[i]);
		b[i]=0;
	}
	cout<<maxans;
	return 0;
} 
