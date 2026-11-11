#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200010];
bool b[200010];
int ans = -1;

void dfs(int i){
	if(i > m){
		int s = 2097151;
		for(int k = 0;k<n;k++){
			if(b[k]) {
				s &= a[k];
				//cout << a[k] << ' ';
			}
		}
		//cout << '/' << s << '\n';
		if(s > ans){
			ans = s;
			
		}
		return;
	}
	if(i == 1){
		for(int j = 0;j<n;j++){
			b[j] = 1;
			dfs(i + 1);
			b[j] = 0;
		}
	}
	for(int j = 0;j<=i;j++){
		if(b[j] == 0){
			b[j] = 1;
			dfs(i + 1);
			b[j] = 0;
		}
		else{
			continue;
		}
	}
}

int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	dfs(1);
	//cout << "/";
	cout << ans;
	return 0;
} 
