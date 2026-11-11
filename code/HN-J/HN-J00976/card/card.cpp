#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10,IF=1e18;
int n,m,a[N],vis[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(s.size()){
					if(s.top()==a[j]){
						break;
					}
					vis[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				vis[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]){
				ans[i]++;
				vis[i]=0;
			}
		}
	}
	for(int i=1;i<m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<ans[m]; 
	return 0;
}
