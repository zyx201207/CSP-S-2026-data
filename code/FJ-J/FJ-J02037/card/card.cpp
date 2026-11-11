#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n,m,vis[5000],a[MAXN],num[MAXN],vis1[MAXN],cnt=0,b[MAXN];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		st.push(a[i]);
		vis[a[i]]=1;
		for(int j=i+1;j<=n;j++){
			if(vis[a[j]]==0){
				st.push(a[j]);
				vis[a[j]]=1;
			}else{
				while(!st.empty()){
					st.pop();
				}
				st.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!st.empty()){
			int x=st.top();
			num[x]++;
			st.pop();
		}
		for(int j=1;j<=n;j++){
			vis[a[j]]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis1[a[i]]==0){
			vis1[a[i]]=1;
			b[++cnt]=a[i];
		}
	}
	for(int i=1;i<=cnt;i++){
		cout<<num[b[i]]<<" ";
	}
	return 0;
}
