#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool f[200005]; 
void dfs(int k,int num){
	if(k+1>m){
		ans=max(num,ans);
		//cout<<k<<" ";
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			dfs(k+1,num&a[i]);
			f[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(1,a[i]);
		f[i]=0;
	}
	cout<<ans;
	return 0;
} 
