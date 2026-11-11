#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,ans[100005],dis[100005],amax,tot;
void check(){
	int lian=0;
	for(int i=1;i<=k-1;i++){
		if(ans[i]+1==ans[i+1]){
			lian++;
			while(i<=n&&ans[i]+1==ans[i+1]) i++;
		}
	}
	if(lian>2) return;
	for(int i=1;i<=n;i++) dis[i]=INT_MAX;
	for(int i=1;i<=n;i++){
		//if(i==1) dis[i]=abs(ans[j]-i);
		for(int j=1;j<=k;j++){
			dis[i]=min(dis[i],abs(ans[j]-i));
			amax=max(amax,dis[i]);
		}
	}
	tot=min(tot,amax);
}
void dfs(int now,int has){
	if(now>n) return;
	ans[has]=now;
	if(has==k) check();
	dfs(now+1,has+1);
	dfs(now+1,has);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t){
		t--;
		cin>>n>>k; 
		for(int i=1;i<=n-1;i++) cin>>u>>v;
		amax=INT_MIN;
		tot=INT_MAX;
		dfs(1,1);
		cout<<tot<<endl;
	}
	return 0;
}
