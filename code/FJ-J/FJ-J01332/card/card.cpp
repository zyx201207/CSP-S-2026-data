#include<bits/stdc++.h>
using namespace std;
const int maxn = 500010;
int a[maxn];
int flag[maxn],ret[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	//小数据(测试点1-3) 
	if(n <= 10 && m <= 5){
		queue<int> q;
		int id = 0;
		while(id <= n){
			memset(flag,0,sizeof(flag));
			id++;
			for(int i = id;i <= n;i++){
				if(flag[a[i]]){
					while(!q.empty()){
						flag[q.front()]--;
						q.pop();
					}
					q.push(a[i]);
					flag[a[i]]++;
				}
				else{
					q.push(a[i]);
					flag[a[i]]++;
				}
			}
			while(!q.empty()){
				ret[q.front()]++;
				q.pop();
			}
		}
		for(int i = 1;i <= m;i++){
			cout << ret[i] << ' ';
		}
	}
	return 0;
}
