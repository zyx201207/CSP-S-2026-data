#include<iostream>
#include<stack>
using namespace std;
#define N 500005
int n, m, a[N], cnt[N];
bool vis[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= m;j++){
			vis[j] = 0;
		}
		stack<int> stk;
		for(int j = i;j <= n;j++){
			if(vis[a[j]]){
				while(!stk.empty() && stk.top()!=a[j]){
					vis[stk.top()]=0;
					stk.pop();
				}
			}else{
				vis[a[j]]=1;
				stk.push(a[j]);
			}
		}
		for(int i = 1;i <= n;i++){
			if(vis[i])cnt[i]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << " ";
	}//感谢陪伴，跨越无数的悲伤与困难 
	cout << endl;
	return 0;
}
