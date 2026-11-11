#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N][30];
int nxt[N];
int head = 1;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	memset(a, 0, sizeof a);
	int n, m;
	cin >> n >> m;
	long long x;
	for(int i = 1, cnt;i <= n;i++){
		nxt[i] = i + 1;
		cin >> x;
		cnt = 0;
		while(x){
			cnt++;
			a[i][cnt] = x % 2;
			x /= 2;
		}
		a[i][0] = cnt;
	}
	nxt[n] = 0;
	int cnt;
	for(int i = 30;i >= 1;i--){
		cnt = 0;
		for(int j = 1;j <= n;j++){
			if(a[j][0] >= i && a[j][i]) cnt++;
		}
		if(cnt >= m){
			x = i;
			break;
		}
	}
	long long ans = 0;
	while(x--){
		cnt = 0;
		for(int i = head;i;i = nxt[i]){
			if(a[i][0] > x && a[i][x + 1])
				cnt++;
		}
		if(cnt >= m){
			ans += pow(2ll, x);
			int le = 0;
			int la = 0;
			for(int i = head;i;i = nxt[i]){
				if(a[i][0] > x && a[i][x + 1]){
					la = i;
					if(le == 0) head = i, le = i;
					else{
						nxt[le] = i;
						le = i;
					}
				}
			}
			nxt[la] = 0;
		}
	}
	cout << ans;
	return 0;
}
