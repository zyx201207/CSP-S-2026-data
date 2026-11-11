#include<bits/stdc++.h>
using namespace std;
long long m,n,a[100001],maxn=0;
bool book[100001];
void dfs(long long s,long long summ){
	if(s==m){
		if(maxn<=summ){
			maxn=summ;	
		}return;
	}for(int i=1;i<=n;i++){
		if(!book[i]){
			book[i]=1;
			dfs(s+1,summ&a[i]);
			book[i]=0;
		}
	}return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];book[i]=0;
	}for(int i=1;i<=n;i++){
		book[i]=1;
		dfs(1,a[i]);
		book[i]=0;
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
