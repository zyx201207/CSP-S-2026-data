#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int n,d;
int ans;
int sum=0;
void dfs(int u,int v,int now,int len){
	if(now==len&&u!=v)return ;
	if(now==len&&u==v)sum++;
	for(int i=u+1;i<=v;i++){
		if(x[i]-x[u]<=d){
			dfs(i,v,now+1,len);
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int v=i+1;v<=n;v++){
				sum=0;
				int len=ceil((float)(v-i)/d);
				dfs(i,v,0,len);
				if(sum==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

