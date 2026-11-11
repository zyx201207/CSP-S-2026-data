#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n,m,a[500005],vis[500005],cnt[500005],flag,ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]< a[i-1]) flag = 1;
	}
	if(!flag){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1])
				cnt[a[i-1]] = ans;
			ans ++;
		}
		cnt[m] = ans;
		for(int i=1;i<=m;i++)
			cout << cnt[i] << ' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(s.top()!=a[j]){
					vis[s.top()] = 0;
					s.pop();
				} 
			}else{
				vis[a[j]] = 1;
				s.push(a[j]);
			}
		}
		while(!s.empty()){
			cnt[s.top()] ++;
			vis[s.top()] = 0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout << cnt[i] << ' ';
	return 0;
}
