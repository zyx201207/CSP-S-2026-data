#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=5e5+5;
int n,m,ans[N];
bool vis[N],vis2[N];
int pos[N];
queue<int> st; 
vector<int> a(N);
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int now=1;now<=n;now++){
		int cnt=0;
		memset(vis2,0,sizeof vis2);
		memset(vis,0,sizeof vis);
		for(int i=now;i<=n;i++){
			if(vis[a[i]]){
				st=queue<int>();
				memset(vis,0,sizeof vis);
				for(int j=1;j<=pos[a[i]]-1;j++)
					st.push(a[j]),vis[j]=1;
				pos[a[i]]=0;
				vis[a[i]]=0;
			}
			st.push(a[i]);
			if(!vis[a[i]]){
				vis[a[i]]=1;
				pos[a[i]]=i;
			}
		}
		for(int j=1;j<=m;j++)
			if(vis[j])
				ans[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
