#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],k[300010],cnt[300010];
void bfs(int l){
	deque<int> q;
	for(;l<=n;l++){
		cnt[a[l]]++;
		if(cnt[a[l]]>1){
			while(1){
				int t=q.back();
				q.pop_back();
				cnt[t]--;
				if(t==a[l]) break;
			}
		}
		q.push_back(a[l]);
	}
	for(int i=1;i<=m;i++){
		k[i]+=cnt[i];
		cnt[i]=0; 
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	for(int i=1;i<=m;i++) cout<<k[i]<<" ";
	return 0;
}
