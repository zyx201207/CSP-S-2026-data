#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000005;
int c,t,vis[MAXN]={},cnt=0;
int n,d,a[MAXN]={};
void f(int xx,int yy){
	queue<int>q;
	q.push(xx);
	vis[xx]=1;
	while(!q.empty()){
		int f=q.front();
		q.pop();
		if(f==yy){
			cnt++;
		}
		for(int i=f+1;i<=n;i++){
			if(a[i]-a[f]<=d&&vis[i]==0){
				q.push(i);
				vis[i]=1;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				f(i,j);
				cout<<cnt<<" ";
				if(cnt==2){
					ans++;
				}
				memset(vis,0,sizeof(vis));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
