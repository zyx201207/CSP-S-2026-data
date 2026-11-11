#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],ans[500005],vis[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		stack<long long> st;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(st.size()!=0){
					int u=st.top();
					if(u==a[j]){
						break;
					}
					vis[u]=0;
					st.pop();
				}
			}else{
				st.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(st.size()!=0){
			int u=st.top();
			ans[u]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
