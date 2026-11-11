#include<bits/stdc++.h>
using namespace std;
queue <char> que;
stack <char> stk;
int n,m,cnt,ans;
char pus,f,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> m >> pus;
		for(int j = 1;j <= m;j++){
			que.push(pus);
			stk.push(pus);
			cnt++;
		}
	}
	while(stk.size() >= cnt / 2 + 1){
		f = que.front();
		b = stk.top();
		if(f != b){
			ans++;
		}
		que.pop();
		stk.pop();
	}
	cout << ans;
	return 0;
}