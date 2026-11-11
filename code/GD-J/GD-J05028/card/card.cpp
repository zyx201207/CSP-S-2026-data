#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500007];
int t[500007];
int top;
bool x[500007];
int ans[500007];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			t[++top] = a[j];
			for(int k = 1; k < top; k++){
				if(t[k]==a[j]){
					top = k;
					t[top] = a[j];
					break;
				}
			}
		}
		for(int k = 1; k <= top; k++){
			if(x[k]==0) ans[t[k]]++; 
		}
		memset(x,0,500007);
		memset(t,0,500007);
	}
	int num=0;
	for(int i = 1; i <= m; i++){
			cout << ans[i] << " ";
	}
	
	return 0;
}
