#include <bits/stdc++.h>

using namespace std;

struct Node{
	int w;
	int last;
	queue<int>s;
}a[1000086];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> a[i].w;
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		int la = 0;
		for (int j = 1; j <= k; j++){
			a[1].last = 0;
			a[2].last = 1;
			int aa,tt;
			cin >> aa >> tt;
			a[aa].last = la;
			la = aa;
			a[aa].s.push(tt);
			
		}
	}
	int sum = 0;
	while (q--){
		sum = 0;
		int x,y;
		cin >> x >> y;
		sum = a[x].w;
		while (!a[x].s.empty()){
			sum += a[x].s.front();
			a[x].s.pop();
		}
		/*
		for (int i = 1; i <= m; i++){
			while (!a[i].s.empty()){
				cout << a[i].s.front() << " ";
				a[i].s.pop();
			}
			cout << '\n';
		}
		*/
		int now = x;
		while (now < y){
			for (int i = 1; i <= m; i++){
				if (a[i].last == now){
					if (i > y)break;
					now = i;
					while (!a[i].s.empty()){
						sum += a[i].s.front();

						a[i].s.pop();
					}
					
				}
			}
		}

		cout << sum+a[now].w << '\n';
	}
	return 0;
} 
