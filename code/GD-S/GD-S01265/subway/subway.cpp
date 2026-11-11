#include<bits/stdc++.h>
const int N=5e5+10;
using namespace std;
int c,n,m,d,q,s,e,ans; 
int w[N],k[510],a[510][N],t[510][N],sd,book[510],book1[510],z;
vector<int>st[510];
queue<int>q1;
int dfs(int u){
	q1.push(u);
	book1[u]=1;
	while(!q1.empty()){
		int top1=q1.front();
		if(top1==e){
			return z; 
		}
		q1.pop();
		for(auto it:st[top1]){
			for(int i=1;i<=k[it];i++){
				if(book[a[it][i]]==0){
					if(book1[top1]==1)book1[a[it][i]]=book1[top1]+1;
					book1[top1]=0;
					z=book1[a[it][i]];
					q1.push(a[it][i]),book[a[it][i]]=1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			st[a[i][j]].push_back(i);
			cout<<st[a[i][j]][j];
		}
	}
	while(q--){
		ans=0;
		cin>>s>>e;
		cout<<(dfs(s)+2)*t[1][1]+w[s]+w[e]<<'\n';
	}
	return 0;
} 
