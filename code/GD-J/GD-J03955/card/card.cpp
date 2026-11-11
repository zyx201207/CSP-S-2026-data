#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
int n,m,a[N],ans[N];
stack<int>stk;
bool vis[N],flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q=0;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if(q>a[i]) flag=0;
		else{
			if (q<a[i]) q=a[i];
		}
	}
	if (flag){
		for(int i=2;i<=n;i++){
			if (a[i]!=a[i-1]) cout << i-1 << ' ';
		}
		cout << n;
		return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (!vis[a[j]]){
				stk.push(a[j]);
				vis[a[j]]=1;
			}else{
				while(1){
					if (a[j]==stk.top()) break;
					vis[stk.top()]=0;
					stk.pop();
				}
			}
		}
		while(stk.size()){
			ans[stk.top()]++;
			vis[stk.top()]=0;
			stk.pop();
		}
	}
	for (int i=1;i<=m;i++)
		cout << ans[i] << ' ';
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
