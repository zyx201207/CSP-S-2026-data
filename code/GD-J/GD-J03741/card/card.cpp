#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000010];
int cnt[1000010];
bool v[1000010];
int ans[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		memset(cnt,0,sizeof(cnt));
		memset(v,0,sizeof(v));
		for(int j = i;j <= n;j++){
			if(cnt[a[j]] == 0){
				cnt[a[j]] = j;
				v[j] = 1;
			}else{
				for(int k = cnt[a[j]];k < j;k++){
					v[k] = 0;
					cnt[a[k]] = 0;
				}
				cnt[a[j]] = j;
				v[j] = 1;
			}
		}
		for(int j = 1;j <= n;j++){
			if(v[j] == 1){
				ans[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
