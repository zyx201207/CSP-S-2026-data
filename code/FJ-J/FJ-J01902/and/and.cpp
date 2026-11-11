#include <bits/stdc++.h>
using namespace std;
int ans=0,maxn=-1,s=1;
int n,m,a[200005];
void dfs(int k,int i){
	if(k==m+1){
		maxn=max(maxn,ans);
		return;
	}
	int temp=ans;
	for(int j=i+1;j<=n;j++){
		if(k==1){
			ans=a[j];
			temp=ans;
		}
		else
			ans&=a[j];
		dfs(k+1,j);
		ans=temp;
	}
}



int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<maxn;
	return 0;
} 
