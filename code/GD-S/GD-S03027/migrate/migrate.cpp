#include<bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
const int N=3007;
int c,t,a[N],cnt,ans,u,v;
int n,d,vis[N];
void dfs(int pos,int stp) {
	if(pos==v) {
		if(stp<ans) ans=stp,cnt=1;
		else if(stp==ans) cnt++;
	}
	for(int i=pos+1;i<=v;i++) {
		if(a[i]-a[pos]<=d) 
			dfs(i,stp+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		int res=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				cnt=0,ans=1000000;
				u=i,v=j;
				dfs(u,0);
				if(cnt==2) res++;
			}
		}
		cout<<res<<'\n';
	}
}

