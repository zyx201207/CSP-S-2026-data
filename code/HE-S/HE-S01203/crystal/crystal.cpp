#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

long long n , m;
long long a[MAXN];
long long sum;//总共的步数
long long ans;//答案 
long long vis;

int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n ; i++)	cin >> a[i];
	sort(a + 1 , a + n + 1); 
	for(int i = 2; i <= n - 1 ; i++)
		if(a[i] - a[i - 1] == a[i + 1] - a[i])	vis++;
	if(vis == n - 2){
		ans = max(sqrt(4 * m + 4) , 2 * sqrt(m));
		cout << ans;
	}
	else{
	for(long long i = 1; i <= n ; i++){//用i颗水晶的最小值 
		for(int j = 1 ; j <= n - i + 1 ; j++){//起始位置 
			sum = 0;
			int k = j + i - 1;//结束位置 
			if(i % 2 == 1){//奇数(奇点偶段) 
				int x = j , y = k;
				while(x != y){
					sum += a[y] - a[x];
					y--;
					x++;
				}	 
				if(sum <= m)	ans = max(ans , i);
			}
			if(i % 2 == 0){//偶数 
				int x = j , y = k;
				while(y - x != 1){
					sum += a[y] - a[x];
					y--;
					x++;
				} 
				if(sum <= m) ans = max(ans , i);
			}
		}
	}
	cout << ans;
}
	return 0;
}
