#include <bits/stdc++.h>
using namespace std;


int n,d;
int x[10000];

void bfs(int x1,int x2,int j){
	int x,step;
	queue<int> a;
	a.push(x1);
	int f[10000] = {0};
	while(a.empty() != 1){
		if(a.front() == x2)f[step] += 1;
		for(int i = 1;i <= d;i++){
			x = x[j + i];
			step += 1;
			a.push(x);
			if(x[j+i]-x[j] > 1)i = x[j+i]-x[j] - 1;
		}
		a.pop();
		
	}
	for(int i = 1;i <= n;i++){
		if(f[i] > 0){
			if(f[i] == 2){
				return 1;
			}else return 0;
		}
	}
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	
	
	for(int t1 = 1;t1 <= t;t1++){
		int cnt = 0;
		cin >> n >> d;
		x = {0};
		for(int i = 1;i <= n;i++){
			cin >> x[i];
			for(int j = 1;j <= i;j++){
//				int dx = x[i] - x[j];
				if(bfs(x[j],x[i],j))cnt++;
			}
		}
		cout << cnt;
	}
	return 0;
}
