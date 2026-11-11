#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int dfs(int u,int v,int ans){
	if(v==0){
		int o=-1000;
		for(int i=u;i<=n;i++){
			o=max(o,ans&a[i]);
		}	
		return o;
	}
	int o=-1000;
	int p;
	for(int i=u;i<=n-v+1;i++){
		if(o<ans&a[i]){
			o=ans&a[i];
			p=i;
		}
	}
	return dfs(p,v-1,o);
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);   cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int u=-100;
		for(int i=1;i<=n;i++)u=max(u,a[i]);
		cout<<u;
		return 0;
	}
	if(m==n){
		int u=a[1];
		for(int i=2;i<=n;i++)u=(u&a[i]);
		cout<<u;
		return 0;
	}
	if(m==2){
		int u=-100;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=m;j++){
				u=max(u,(a[i]&a[j]));
			}
		}
	}
	cout<<dfs(1,m,(1<<32-1));
}

