#include<bits/stdc++.h>
using namespace std;

struct Node{
	bool mk;
	int f;
}s[10001000];
int n, m;
int a[10000100];
int ans[1000100];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	
	
	for(int i = 1; i <= n; i ++){
		memset(s, 0, sizeof(s));
		for(int j = i; j <= n; j ++){
			if(s[a[j]].mk){
				for(int k = s[a[j]].f; k <= j; k ++) s[a[k]].mk = 0;
				s[a[j]].mk = 1;
				s[a[j]].f = j;
				
			}else {
				s[a[j]].mk = 1;
				s[a[j]].f = j;
			}
		}
		
		for(int i = 1; i <= m; i ++) if(s[i].mk) {ans[i] ++;}
	}
	
	for(int i = 1; i <= m; i ++) cout << ans[i] << " ";
	
	return 0;
} 
