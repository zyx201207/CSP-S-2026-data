#include <bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
int a[200005],b[200005];
void dfs(int i,int j){
	b[j]=a[i];
	if(j==m){
		int p=b[1];
		for(int t=2;t<=m;t++){
			p=(p&b[t]);
		}
		ans=max(ans,p);
		return;
	}
	for(int t=i+1;t<=n-(m-j);t++){
		dfs(t,j+1);
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
		dfs(i-1,1);	
	}
	cout<<ans;
}
