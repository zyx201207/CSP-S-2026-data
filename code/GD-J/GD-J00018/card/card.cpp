#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[400005],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
		    cnt++;
		    for(int j = 1;j <= n;j++){
		    	if(a[i] == d[j]){
		    		cnt = j;
		    		for(int v = j;v <= i-1;v++){
		    			d[v] = 0;
					}
					break;
				}
			}
			d[cnt] = a[i];
		}
	}
	for(int i = 1;i <= m;i++){
		int ans = 0;
		for(int j = 1;j <= n;j++){
			if(d[j] == i) ans++;
		}
		cout << ans << " "; 
	}
	
	return 0;
}
