#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010]; 
int st[300010];
int ans[300010];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>sta;
		memset(st,0,sizeof st);
		for(int j=i;j<=n;j++){
			if(st[a[j]]){
				while(sta.top()!=a[j]){
					st[sta.top()]=0;
					sta.pop();
				}
			}
			else {
				sta.push(a[j]);
				st[a[j]]=1;	
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=st[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
