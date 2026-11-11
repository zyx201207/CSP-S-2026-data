#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int cnt[500005];
int pos[500005];
bool is_used[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int ju = 1;
	int c = 0;
	while (ju <= n){
		for (int i = ju;i <= n;i++){
			if (!is_used[a[i]]){
				is_used[a[i]] = true;
				cnt[a[i]]++;
				pos[a[i]] = i;
			}else{
				for (int j = pos[a[i]];j < i;j++){
					is_used[a[j]] = false;
					cnt[a[j]]--;
					c++;
				}
				is_used[a[i]] = true;
				cnt[a[i]]++;
				pos[a[i]] = i;
			}
		}
		ju++;
	}
	for (int i = 1;i <= m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
} 
