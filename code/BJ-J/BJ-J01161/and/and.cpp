#include <bits/stdc++.h>
using namespace std;
long long a[200009],visited[10000];
long long n,m,maxx=0;
void dfs(long long num,long long i,long long c){
	if(c==m){
		maxx=max(maxx,num);
		return;
	}
	for(int j=i+1;j<n;j++){
		if(!visited[j]){
			visited[j]=1;
			dfs((num&a[j]),j,c+1);
			visited[j]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)visited[i]=0;
	for(int i=0;i<n-m;i++){
		dfs(a[i],i,1);
	}
	cout<<maxx;
	fclose(stdin);fclose(stdout);
	return 0;
}
