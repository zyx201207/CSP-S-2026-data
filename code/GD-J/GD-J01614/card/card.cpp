#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10,M=3e5+10;

int n,m,a[N],cnt[M];
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	
	for(int i=1;i<=n;i++){
		stack<int>st;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(st.top()!=a[j]&&!st.empty()){
					st.pop();
				}
			}
			else{
				vis[a[j]]=1;
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			cnt[st.top()]++;
			st.pop();
		}
		for(int i=1;i<=m;i++)vis[i]=0;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
}

