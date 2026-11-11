#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
const int N = 500010,M = 300010;
int n,m;
int a[N];
int w[N];
int ww[N],ans[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	bool f = true;
	for(int i = 1;i <= n;i++){
		if(a[i]<a[i-1])f = false;
	}
	if(f){
		for(int i = 1;i <= n;i++)w[a[i]]++;
		ll pre = 0;
		for(int i = 1;i <= m;i++){
			pre+=w[i];
			cout << pre << ' ';
		}
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++)w[i] = 0;
		int cnt = 0;
		for(int j = i;j <= n;j++){
			for(int k = 1;k <= cnt;k++){
				if(w[k]==a[j]){
					for(int p = k;p <= cnt;p++)w[p] = 0;
					cnt = k-1;
					break;
				}
			}
			w[++cnt] = a[j];
		}
		for(int i = 1;i <= cnt;i++){
			ww[w[i]] = true;
		}
		for(int i = 1;i <= m;i++){
			ans[i]+=ww[i];
			ww[i] = false;
		}
	}
	for(int i = 1;i <= m;i++)cout << ans[i] << ' ';
	return 0;
}
