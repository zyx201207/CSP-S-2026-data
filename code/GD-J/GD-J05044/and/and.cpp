#include<bits/stdc++.h>
using namespace std;
//dp?
int vis[200005],a[200005],n,m,ans=0;
void dfs(int num,int k,int now){
	if(vis[k])return;
	if(n-k+now<m)return;
	if(now==m-1){
		ans=(ans>num?ans:num);
	}
	vis[k]=1;
	for(int i=k+1;i<n;i++){
		dfs((num & a[i]),i,now+1);
	}
	vis[k]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	int tmp=a[0];
	for(int i=1;i<m;i++){
		tmp&=a[i];
	}//cout<<tmp<<' ';
	for(int i=m;i<n-m+1;i++){
		if(tmp>a[i+m])break;
		int tmp1=a[i];
		for(int j=0;j<m;j++){
			tmp1&=a[j+i];
		}
		tmp=max(tmp,tmp1);
	}cout<<tmp;
//	for(int i=0;i<n;i++){
//		//dfs(a[i],i,0);
//		
//	}cout<<ans;
	return 0;
}
