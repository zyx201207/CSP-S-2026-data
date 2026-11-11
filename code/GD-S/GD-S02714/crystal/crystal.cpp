#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int vis[N];
int cnt;
int n,m;
int ans;
void dfs(int k,int now,int total){
	if(now==total&&(cnt+m)%total==0){
		int temp=(cnt+m)/now;
		int flag=0;
		int maxx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				maxx=max(maxx,a[i]);
			}
		}
		if(temp>=maxx){
			for(int i=1;i<=n;i++){
				if(vis[i]){
					flag=flag+(temp-a[i]);
					//cout<<a[i]<<" ";
				}
			}
			//cout<<endl;
			if(flag==m)ans=max(ans,now);
			else return;
		}
		else return;
	}
	for(int i=k+1;i<=n;i++){
		if(!vis[i]){
			cnt+=a[i];
			vis[i]=1;
			dfs(i,now+1,total);
			vis[i]=0;
			cnt-=a[i];
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		//cout<<i<<" ";
		for(int j=1;j<=n;j++){
			memset(vis,0,sizeof(vis));
			cnt=a[j];
			vis[j]=1;
			dfs(j,1,i);
			vis[j]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}

