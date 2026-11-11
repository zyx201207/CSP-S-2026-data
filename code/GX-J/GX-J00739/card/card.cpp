#include<bits/stdc++.h>
using namespace std;

const int N =500005,M = 300005;
int n,m;
int a[N];
int ans[M];
int v[N];

int game(int x){
	int cnt = 1;
	for(int i = x;i <= n;i++){
		v[cnt] = a[i];
		for(int j = x;j < i;j++){
			if(v[cnt] == v[j]){
				for(int k = j;k <= cnt;k++) v[k] = 0;
				cnt = j;
				v[cnt] = a[i];
			}
		}

		cnt++;
	}
	return cnt;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		memset(v,0,sizeof(v));
		int id = game(i);
		for(int j = 1;j <= id;j++){
			ans[v[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
