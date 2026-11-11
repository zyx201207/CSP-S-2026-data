#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N];
queue<int>q;
bool vis[N];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(n--){
		for(int i=1;i<=n;i++){
			if(vis[a[i]]==1){
			    while(q.front()!=a[i]){
			    	q.pop();
				}
		    }
		    q.pop();
		    q.push(a[i]);
		    cnt[a[i]]++;
			vis[a[i]]=1;
		}
		while(!q.empty())q.pop();
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
