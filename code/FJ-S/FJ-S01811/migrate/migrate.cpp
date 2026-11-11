#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t;
int n,d,x[N],len[N],num[N];
void solvea(){
	if(len[2]>d){
		cout<<"0\n";
		return;
	}
	int cnt=d/len[2],cnt1=cnt,ans=0;
	if(cnt==1){
		cout<<"0\n";
		return;
	}
	n--;
	while(n-cnt-cnt1+1>=0){
		ans+=n-cnt-cnt1+2;
		cnt*=2;
	}
	cout<<ans<<'\n';
}
vector<int>g[N];
void dfs(int u){
	for(int v:g[u]){
		if(len[u]+1==len[v])num[v]++;
		else if(len[u]+1<len[v]){
			num[v]=1;
			len[v]=len[u]+1;
//			cout<<u<<' '<<v<< ' '<<len[v]<<'\n';
		}
		dfs(v);
	}
}
void solve(){
	cin>>n>>d;
	int ans=0;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		g[i].clear();
		len[i]=x[i]-x[i-1];
		if(i>2)f=len[i]==len[i-1];
	}
//	if(f)solvea();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				g[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)len[j]=LLONG_MAX,num[j]=0;
		len[i]=0;
		dfs(i);
		for(int j=i+2;j<=n;j++){
//			cout<<len[j]<<' '<<num[j]<<'\n';
			ans+=num[j]==2;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
