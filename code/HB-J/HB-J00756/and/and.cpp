#include<bits/stdc++.h>
using namespace std;
int arr[3000],vis[3000];
int n,m;
int dfs(int n1,int m1){
	if(m1==1)return arr[n1];
	int ans=0;
	vis[n1]=1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){int k=arr[n1]&dfs(i,m1-1);
			if(k>ans)ans=k;
		}
	}
	vis[n1]=0;
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dfs(i,m));
	}
	cout<<maxn<<endl;
	return 0;
}
