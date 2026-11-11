#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int cnt[1000010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		queue<int>q;
		for(int j=i-1;j<=n;j++){
			q.push(a[j]);
			bool f=1;
			int cnt=q.size();
			while(cnt--){
				int cur=q.front();
				q.pop();
				if(cur==a[j]){
					q.push(a[j]);
					f=0;
				}
				else if(f) q.push(cur);
			}
		}
		while(!q.empty()){
			int cur=q.front();
			cnt[cur]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
