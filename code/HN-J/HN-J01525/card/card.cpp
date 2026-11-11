#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[300005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = 1;i <= n;i ++){
		memset(c,0,sizeof(c));
		int t = 0; 
		for(int j = i;j <= n;j ++){
			bool f = 0;
			for(int k = 1;k <= t;k ++)
				if(c[k] == a[j]){
					f = 1;
					t = k;
					break;
				}
			if(f) c[t] = a[j];
			else c[++t] = a[j];
		}
		for(int j = 1;j <= t;j ++) vis[c[j]] ++;
	}
	for(int i = 1;i <= m;i ++) cout << vis[i] << ' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
