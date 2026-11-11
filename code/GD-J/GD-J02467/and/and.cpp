#include<bits/stdc++.h>

using namespace std;

int n,m,ans = 0;
int a[200005];

void dfs1(int x,int sum,int ad){
	if(sum == m){
		ans = max(ans,ad);
	} 
	for(int i = x + 1;i <= n;i++){
		dfs1(i,sum + 1,ad & a[i]);
	}
}


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 20){
		for(int i = 1;i <= n;i++){
			dfs1(i,1,a[i]);
		}
	}else{
		if(n <= 2000){
			if(m == 1){
				for(int i = 1;i <= n;i++){
					ans = max(ans,a[i]);
				}
				cout<<ans;
			}else if(m == 2){
				for(int i = 1;i <= n - 1;i++){
					for(int j = i + 1;j <= n;j++){
						ans = max(ans,a[i] & a[j]);
					}
				}
				cout<<ans;
			}else{
				ans = a[1];
				for(int i = 2;i <= n;i++){
					ans = a[i] & ans;
				}
				cout<<ans;
			}
		}else{
			
		}
	}
	cout<<ans;
}
