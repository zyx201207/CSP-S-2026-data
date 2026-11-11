#include<bits/stdc++.h>
using namespace std;
int ans[300005],n,m,b[500005],ans1[500005];
vector<int>a[300005];
int g[500005];
void dfs(int i){
	if(g[i]||i==n+1)return;
	int l=0,r=a[b[i]].size()-1,d=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[b[i]][mid]<=i){
			d=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	
	if(d!=(int)a[b[i]].size()-1)g[i]=a[b[i]][d+1];
	else g[i]=i+1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[b[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		dfs(i);
		ans[i]=1;
	}
	for(int i=1;i<=n;i++)ans[g[i]]+=ans[i];
	for(int i=n;i>0;i--)if(g[i]==i+1)ans1[b[i]]+=ans[i];
	for(int i=1;i<=m;i++)cout<<ans1[i]<<' ';
	return 0;
}