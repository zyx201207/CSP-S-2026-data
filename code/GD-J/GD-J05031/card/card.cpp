#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	stack<int> s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) vis[j]=0;
		while(!s.empty()) s.pop();
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				s.push(a[j]);
			}else{
				while(1){
					int x=s.top();
					if(x==a[j]) break;
					s.pop();
					vis[x]=0;
				}
			}
		}
		for(int j=1;j<=m;j++) ans[j]+=vis[j];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

