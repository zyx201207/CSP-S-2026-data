#include<bits/stdc++.h>
using namespace std;
int a[500010];
int vis[300010];
int sum[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]=i; 
	}
	for(int i=1;i<=n;i++){
		int len=i;
		int k=1;
		while(len<=n){
			sum[a[len]]++;
			len=vis[a[len]]+1;
			k++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
