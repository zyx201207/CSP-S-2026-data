#include<bits/stdc++.h>
using namespace std;
int x[100000],d;
int ans=0;

int dfs(int q,int z){
	if(x[z]-x[q]<=d){
		return 1;
	}
	int i=q+1,h=1000000,hi=1;
	while(x[i]-x[q]<=d&&i<z){
		int n=dfs(i,z);
		if(h>n){
			h=n;
			hi=1;
		}
		else if(n==h){
			hi++;
		}
		i++;
	}
	if(hi==2){
		ans++;
	}
	return h+1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int  c,t;
	cin >> c >> t;
	for(int a=0;a<t;a++){
		int n;
		cin >> n >> d;
		for(int i=0;i<n;i++){
			cin >> x[i];
		}
		int ans=0;
		for(int i=0;i<n-1;i++){
			dfs(i,n);
		}
		cout << ans;
	}
}
