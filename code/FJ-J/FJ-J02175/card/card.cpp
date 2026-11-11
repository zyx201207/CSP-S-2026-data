#include<bits/stdc++.h>

using namespace std;

const int maxn = 500050;

int n,m;
int a[maxn];
bool b[maxn];
int cards[maxn];
int cnt[maxn];
int idx;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			b[j] = 0;
		}
		idx = 1;
		for(int j = i;j <= n;j++){
			if(!b[a[j]]){
				b[a[j]] = 1;
				cards[idx] = a[j];
				idx++;
			} else {
				int x = 1;
				for(int k = 1;k <= idx;k++){
					if(cards[k] == a[j]){
						x = k;
						break;
					}
				}
				for(int k = x + 1;k <= idx;k++){
					b[k] = false;
				}
				idx = x + 1;
			}
		}
		for(int j = 1;j <= idx;j++){
			cnt[cards[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
