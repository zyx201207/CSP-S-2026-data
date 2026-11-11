#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,w[500001],k[501];
long long maxn,ans;
bool flag1,flag2;
struct node{
	int names,t;
};
map<int,int>mp[500005];
int record[500005];
	int a[500005],t[500005];
void dfs(int now,long long spend){
	if(spend>ans)	return;
	if(now==y)	ans=min(ans,spend);
	dfs(record[now],spend+mp[now][record[now]]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i],maxn+=w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2)	flag1=1;
	
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			maxn+=t[j];
			
		}
		mp[a[1]][a[2]]=mp[a[2]][a[1]]=t[1]+t[2];
		record[a[1]]=(a[2]);
		record[a[2]]=(a[1]);
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=2*maxn;
		//cout<<mp[1][1]<<" "<<mp[2][1]<<" "<<mp[3][1]<<" "<<mp[3][2]<<" ";
		if(!flag1){
			
			dfs(x,w[x]+w[y]);
			cout<<ans;
		}
		
	}
	return 0;
}