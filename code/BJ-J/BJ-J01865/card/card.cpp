#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+5, M = 3e3+5;
int n, m;
int a[N], ans[M];
int desk[N]; //桌面上的卡牌分数

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){ //第 i 轮
		for(int add=i; add<=n; add++){ //加入第 add 个卡牌
			int pos = 1; //a[add] 应该插入的位置
			for(; desk[pos]!=0; pos++) {
				if(desk[pos] == a[add]) break;
			}
			desk[pos] = a[add];
			desk[pos+1] = 0;
		}
		for(int j=1; desk[j]!=0; j++){
			ans[desk[j]]++;
		}
		memset(desk, 0, sizeof desk);
	}
	for(int i=1; i<=m; i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
