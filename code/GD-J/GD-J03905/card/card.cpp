#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+10;
const int maxm=3*1e5+10;
long long n,m,a[maxn],ans[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool vis[maxn];
		stack<int>st;
		for(int k=1;k<=m;k++){
			vis[k]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
			}
			else{
				st.push(a[j]);
				vis[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]==1){
				ans[j]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
