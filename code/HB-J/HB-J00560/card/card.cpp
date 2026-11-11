#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,t,a[MAXN],kl,ans[MAXN];
int book[MAXN];
void dfs(int num,int idx){
	if(num==idx+1){
		for(int i=1;i<=idx;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			kl++;
			ans[kl]=a[i];
			book[i]=1;
			dfs(num+1,idx);
			book[i]=0;
			kl--;
		}
	}
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,t);
	/*
	  4 2
	  3 15 12 12
	 */
	return 0;
}
