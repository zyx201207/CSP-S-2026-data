#include <bits/stdc++.h>
using namespace std;
//56+A(4)=60pts
int a[500100];
int d[500100];
bool flag[500100];
int ans[500100];
int mp[501000];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	int m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		fill(flag + 1, flag + n + 1, 0), fill(d + 1, d + n + 1, 0);
		int l = 1;
		for(int j = i;j <= n;j++){
			d[l] = a[j];
			if(d[l] == d[l - 1]){
				
			}else l++;
		}
//		cout << l << endl;
		for(int j = 1;j <= n - i + 1;j++){
			if(d[j] == 0) continue; 
			if(!mp[d[j]]){
				mp[d[j]] = j;
			}else{
				for(int i1 = mp[d[j]];i1 < j;i1++){
					mp[d[i1]] = 0;
					d[i1] = 0;
				}
				mp[d[j]] = j;
			}
		}
		for(int j = 1;j <= l;j++){
			ans[d[j]]++;
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << " "; 
}
