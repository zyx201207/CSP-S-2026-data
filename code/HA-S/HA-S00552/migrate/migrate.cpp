#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
long long c,t,n,d,ans,x[2000010],minn,cnt;
void dfs(int u,int v,int pos,int step){
	if(pos==v){
		if(step<minn){
			minn=step;
			cnt=1;
		}
		else if(step==minn){
			cnt++;
		}
		return;
	}
	for(int i=pos+1;i<=v;i++){
		if(x[i]-x[pos]<=d){
			dfs(u,v,i,step+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int u=1;u<=n;u++){
			for(int v=u+2;v<=n;v++){
				minn=9e18,cnt=0;
				dfs(u,v,u,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//8
