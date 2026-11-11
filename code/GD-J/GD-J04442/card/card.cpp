#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m;
int a[maxn],c[maxn];
bool vis[maxn];
stack<int> t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(!vis[a[j]]){
				t.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(t.top()!=a[j]){
					int cur=t.top();
					vis[cur]=0;
					t.pop();
				} 
			}
		}
		for(int j=1;j<=m;++j){
			if(vis[j]){
				vis[j]=0;
				c[j]++;
			} 
		}
		while(!t.empty()) t.pop();
	}
	for(int i=1;i<=m;++i) cout<<c[i]<<" ";
	return 0;
}
