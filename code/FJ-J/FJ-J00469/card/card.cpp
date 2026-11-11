#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[5*100000+5];
int ans[3*100000+5];
bool c[3*100000+5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i= 1;i <= n; i++){
		cin >>a[i];
	}
	for(int o = n; o >= 1; o--){
		//memset(c,0,sizeof(c));
		if(c[a[o]] == 1){
			int i = o+1;
			while(a[i] != a[o] && i <=n){
				c[a[i]] = 0;
				i++;
			}
			c[a[o]] = 1;
		}else{
			c[a[o]] = 1;
		}
		for(int i = 1; i <= m; i++){
			if(c[i]){
				ans[i] ++;
			}
		}
	}
	for(int i= 1;i <= m; i++){
		cout << ans[i] <<" ";
	}
	return 0;
} 
