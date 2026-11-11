#include<bits/stdc++.h>
using namespace std;

int main(){
	
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	
	int n,m;int sum[1000000];
	cin>>n>>m;
	int a[510005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k>=n;k++){
	int v[1000000]={};
	 int vis[1000000]={};
	for(int i=1;i<=n;i++){
		if(v[a[i]]&&!vis[i]){
			for(int j=v[i];j<i;j++)vis[j]=1;
		}
		v[a[i]]=i;
	}
	for(int i=1;i<=n;i++)if(!vis[i])sum[a[i]]++;
}
for(int i=1;i<=n;i++)cout <<sum[i];
}

