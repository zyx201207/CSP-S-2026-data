#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
const int maxm=3e5+7;
int n,m;
int a[maxn];
int cnt[maxm],vis[maxm];
deque<int> dq;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!dq.empty()) dq.pop_front();
		for(int j=1;j<=m;j++) vis[j]=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(dq.back()!=a[j]){
					vis[dq.back()]=0;
					dq.pop_back();
				}
			}
			else{
				vis[a[j]]=1;
				dq.push_back(a[j]);
			}
		}
		while(!dq.empty()){
			cnt[dq.front()]++;
			dq.pop_front();
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
