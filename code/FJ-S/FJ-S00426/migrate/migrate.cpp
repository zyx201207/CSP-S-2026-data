#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
bool vis[2000005];
struct node{
	int l,m;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				queue<node> q;
				q.push({0,i});
				for(int k=1;k<=n;k++){
					vis[k]=0;
				}
				vis[i]=1;
				int sh=-1;
				while(q.size()){
					node now=q.front();
					q.pop();
					if(now.m==j){
						sh=now.l;
						break;
					}
					for(int nex=now.m+1;nex<=n;nex++){
						if(!vis[nex]&&a[nex]-a[now.m]<=d){
							node ne={now.l+1,nex};
							q.push(ne);
							vis[nex]=1;
						}
					}
				}
				if(sh==-1){
					continue;
				}
				for(int k=1;k<=n;k++){
					vis[k]=0;
				}
				vis[i]=1;
				stack<node> st;
				int cnt=0;
				while(st.size()){
					node now=st.top();
					st.pop();
					if(now.m==j&&now.l==sh){
						cnt++;
					}
					vis[now.m]=0;
					for(int nex=now.m+1;nex<=n;nex++){
						if(vis[nex]==0&&a[nex]-a[now.m]<=d){
							node ne={now.l+1,nex};
							st.push(ne);
							vis[nex]=1;
						}
					}
				}
				if(cnt==2){
					ans++;
				} 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
