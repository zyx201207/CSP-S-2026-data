#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;
int a[N];
int ans[N];
bool vis[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	stack<int> c,ec;
	for(int i=1;i<=n;i++){//每一局游戏
		while(!c.empty()) c.pop();
		while(!ec.empty()) ec.pop();
		 
		for(int j=i;j<=n;j++){//每一张牌
			bool f=0;
			while(!c.empty()){
				if(a[c.top()]==a[j]) f=1;
				ec.push(c.top());
				c.pop();
			}
			
			while(!ec.empty()){
				c.push(ec.top());
				ec.pop();
			}
			if(!f) c.push(j);
			else{
				while(!c.empty() && a[c.top()]!=a[j]){
					c.pop(); 
				}
				c.pop(); 
				c.push(j);
			}
		}
		while(!c.empty()){
			ec.push(c.top());
			ans[a[c.top()]]++;
			c.pop();
		}
		
		while(!ec.empty()){
			c.push(ec.top());
			ec.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 
