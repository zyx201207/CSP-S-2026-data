#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[300005],ans[300005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(vis[a[j]]){
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}else{
				vis[a[j]]=1;
				s.push(j);
			}
		}
		for(int j = 1;j <= m;j++){
			if(vis[a[j]])ans[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
	    cout << ans[i] << ' ';
	} 
	return 0;
}
