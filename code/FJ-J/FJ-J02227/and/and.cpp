#include <bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=2*1e5+5;
bool vis[MAXN];
long long a[MAXN];
long long choose[MAXN];
long long ans=-100,sum=0;
void dfs(int step){
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			choose[step]=a[i];
			vis[i]=true;
		}
		if(step==m){
	        sum=choose[1];
		for(int w=2;w<=step;w++){
			sum=sum&choose[w];			
		}
		ans=max(ans,sum);
		sum=0;
		return ;
	}
		dfs(step+1);
		vis[i]=false;
		choose[step]=0;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	memset(vis,false,sizeof(vis));
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
