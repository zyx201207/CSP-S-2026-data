#include "bits/stdc++.h"
using namespace std;

int n,m,pre[300005],a[500005],ans[500005];
bool vis[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	int ss1=0,ss2=0,ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) ss1++;
		if(a[i]==2) ss2++;
		if(a[i]<a[i-1]) ok=0;
	} 
	
	if(m==1) {
		cout<<n<<endl;
		return 0;
	}
	
	else if(m==2){
		if(a[n]==1) cout<<n<<" "<<ss2<<endl;
		else cout<<ss1<<" "<<n<<endl;
		return 0;
	}
	
	else if(ok){
		int pre=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=pre) cout<<i-1<<" ";
			pre=a[i];
		}
		return 0;
	}
	
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		memset(pre,0,sizeof(pre));
		for(int j=i+1;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				pre[a[j]]=j;
			}
			else{
				for(int k=pre[a[j]];k<j;k++) vis[a[k]]=0;
				pre[a[j]]=j;
				vis[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]) ans[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
