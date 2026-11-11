#include <bits/stdc++.h>
using namespace std;
const int N=2e6;
int c,t,n,sum;
long long d,x[N],ans,mins;
bool vis[N];
struct node{
	long long a,step;
};
void dfs(int u,int v,int step){
	if(step>mins){
		return ;
	}
	if(u==v){
		if(step<mins){
			sum=1;
			mins=step;

		}
		else if(step==mins){
			sum++;
		}
		return ;
	}
	for(int i=u+1;i<=v&&abs(x[i]-x[u])<=d&&!vis[i];i++){
		vis[i]=1;
		dfs(i,v,step+1);
		vis[i]=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			vis[i]=0;
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				mins=1e18;
				sum=0;
				vis[u]=1;
				dfs(u,v,0);
				if(sum==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
