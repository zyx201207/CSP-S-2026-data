#include<bits/stdc++.h>
using namespace std;
const int N = 500005, maxn = 0x3f3f3f3f;
int a[N], cnt, c, n, m;
long long sum;
priority_queue<int> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	//for(int i = 1; i <= n; i++) cout << a[i]<<" ";
	c = a[2] - a[1];
	for(int i = 2; i <= n; i++){
		if(!a[i] - a[i-1] == c){
			cnt++;
			break;
		}
	}
	//cout << cnt << " \n";
	if(cnt == 1){
		int x = 0;
		cnt = 0;
		while(x<=m){
			cnt++;
			x += cnt*c;
			//cout << x << " ";
		}
		cout << cnt;
		return 0;
	}
	cnt = 0;
	int maxn = 0;
	for(int i = n; i >= 2; i--){
		sum = 0;
		for(int j = n - 1; j >= 1; j--){
			sum += (a[i]-a[j]);
			cnt++;
			if(sum > m)
				break;
			else if(sum == m){
				cnt++;
				break;
			}
		}
		maxn = max(maxn, cnt);
		cnt = 0;
	}
	cout << maxn - 1;
	return 0;
}
/*4 9
2 5 8 11*/
