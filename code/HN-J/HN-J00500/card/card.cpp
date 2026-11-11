#include<bits/stdc++.h>
using namespace std;
bool f = false;
int find(int g[50005],int i,int ans){
	if(f){
		return i;
	}
	if(g[i] == ans){
		return i;
	}
	return find(g,i+1,ans);
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,a[50005],d[50005];
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		cout<<"hello";
		int vis[50005] = {},g[50005];
		int ans = n,k = 0;
		for(int j = i;j<n;j++){
			if(!vis[a[j]]){
				ans = find(g,i,a[j]);
				f = false;
				for(int t = ans;t<j;t++){
					g[t] = 0;
				}
				k = ans;
			}
			g[k] = a[j];
			k++;
		}
		for(int j = 0;j<k;j++){
				cout<<"hello"; 
			d[g[j]]++;
		}
	}
	for(int i = 0;i<m;i++){
		cout<<d[i]<<" ";
	}

	return 0;
}
