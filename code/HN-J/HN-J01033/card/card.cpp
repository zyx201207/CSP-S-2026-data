#include<bits/stdc++.h>
using namespace std;
int a[505],tong[505];
bool vis[5005];
queue<int>q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	int n,m;
	cin >>n >>m;
	for(int i = 1;i <= n;i ++){
		cin >>a[i];
	}
	for(int i = 1;i <= n;i ++){
		memset(vis,0,sizeof vis);
		for(int j = i;j <= n;j ++){
			if(!vis[a[j]]){
				q.push(a[j]);
				vis[a[j]] = 1;
			}else{
				for(int k = i;k <= j - 1;k ++){
					q.pop();
					vis[k] = 0;
				}
				q.push(a[j]);
				vis[a[j]] = 1;
			}
		}
		while(!q.empty()){
			tong[q.front()] ++;
			q.pop();
		}
	}
	for(int i = 1;i <= m;i ++)cout <<tong[i] <<' ';
	return 0;
}
