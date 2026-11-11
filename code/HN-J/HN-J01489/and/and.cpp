#include<bits/stdc++.h>
using namespace std;
int n , cnt, m , t[200005] , a[200005]  , vis[200005], maxx;
int f(int x , int y){
	string a , b;
	while(x){
		a = char((x % 2) + '0') + a;
		x /= 2; 
	}
	while(y){
		b = char((y % 2) + '0') + b;
		y /= 2; 
	}
	int len = min(a.size() , b.size());
	string tmp;
	for(int i = 0; i < len; ++i){
		if(a[i] == '1' && b[i] == '1'){
			tmp = '1' + tmp;
		}else{
			tmp = '0' + tmp;
		}
	}
	int p = 0;
	for(int i = 0; i < tmp.size(); ++i){
		p += pow(2 , i) * int(tmp[i] - '0');
	}
	return p;
}
void dfs(int x){
	if(x == m){
		int ans = t[1];
		for(int i = 2; i <= m; ++i){
			ans = f(ans , t[i]);
		}
		maxx = max(ans , maxx);
		return;
	}
	for(int i = 1; i <= n; ++i){
		if(vis[i] == 0){
			vis[i] = 1;
			t[x+1] = a[i];
			dfs(x+1);//选了x+1个数 
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	scanf("%d %d" , &n , &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d" , &a[i]);
	}
	dfs(0);	//已经选了0个数
	printf("%d\n" , maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
