#include<bits/stdc++.h>
using namespace std;
int n,m,a[500002],cnt[300002];
int f[300002],tmp[500002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j <= m;j++)f[j] = -1;
		int p = -1;
		//mset
		for(int j = i;j < n;j++){
			if(f[a[j]] == -1){
				f[a[j]] = ++p;
				tmp[p] = a[j];
			}
			else{
				for(;p > f[a[j]];p--){
					f[tmp[p]] = -1;
				}
				p = f[a[j]];
			}
		}
		for(int j = 0;j <= p;j++){
			cnt[tmp[j]]++;
		}
	}
	for(int i = 1;i <= m;i++)cout << cnt[i] << " ";
	return 0;
}
