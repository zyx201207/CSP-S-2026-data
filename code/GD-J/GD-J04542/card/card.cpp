#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s,vi[500005],f[500005];
bool vis[500005],noj[500005];
stack<int> stk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m; 
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}for(int j = 1;j <= n;j++){
		memset(vis,0,sizeof(vis));
		memset(noj,0,sizeof(noj));
		while(!stk.empty())
			stk.pop();
		s = 0;
		for(int i = j;i <= n;i++){
			if(vis[a[i]]){
				do{
					stk.pop();
					s--;
				}while(stk.top() != a[i]);
			}else
				vis[a[i]] = 1;
			stk.push(a[i]);
			s++;
		}for(int i = 1;i <= s;i++){
			if(!noj[a[i]])
				vi[a[i]]++;
			noj[a[i]] = 1;
		}
	}for(int i = 1;i <= m;i++)
		cout << vi[i] << ' ';
	return 0;
}
