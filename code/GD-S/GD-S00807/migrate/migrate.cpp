#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000005] = {};
int b[2000005] = {};
int ans;
bool dfs(int f,int l){
	b[l] = 1;
	for(int i = l-1;i>=f;i--){
		b[i] = 0;
		int mi = 0;
		if(a[l]-a[i]<=d){
			b[i] = 1;
			continue;
		}
		for(int j = i+1;j<=l;j++){
			if(a[j]-a[i]>d){
				break;
			}
			if(b[i] == 0) {
				b[i] = b[j];
				mi = b[i];
			}
			else if(b[j]<mi){
				b[i] = b[j];
				mi =b[i];
			}
			else if(b[j] == mi){
				b[i]++;
			}
		}
	}
//	for(int i = f;i<=l;i++){
//		cout<<b[i];
//	}
	if(b[f] == 2) return true;
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int blblbl = 0;blblbl<t;blblbl++){
		cin>>n>>d;
		ans = 0;
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}dfs(0,4);
		for(int i = 0;i<n-1;i++){
			for(int j = i+1;j<n;j++){
				if(dfs(i,j)){
					ans++;
				} 
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
