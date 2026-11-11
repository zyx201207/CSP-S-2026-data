#include<bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[114514];
bool b[114514];
void dfs(int num,int cnt=0,int i=1){
	if(cnt==m){
		maxn=max(maxn,num);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			dfs(num&a[i],cnt+1,i+1);
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
	dfs(a[1]);
	cout<<maxn;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
