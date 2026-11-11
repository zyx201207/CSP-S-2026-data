#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,M=3e5+10;
ll n,m,a[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int j=1;
	while(j<=n){
		int vis[5010];
		deque<int>dq;
		for(int i=j;i<=n;i++){
			if(vis[a[i]]){
				while(dq.back()!=a[i]){
					vis[dq.back()]=0; 
					dq.pop_back();
				} 
			}else{
				dq.push_back(a[i]);
				vis[a[i]]=1;
			}
		}
		for(int x:dq) ans[x]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 
