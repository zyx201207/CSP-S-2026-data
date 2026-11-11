#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],sum[300005];
bool vis[500005];
signed main(){
	ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				s.push(a[j]);
			}else{
				while(true){
					if(s.empty()) break;
					if(s.top()==a[j]) break; 
					vis[s.top()]=0;
					s.pop();
				}
			}
		} 
		while(!s.empty()){
			sum[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
