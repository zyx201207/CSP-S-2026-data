#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int cnt;
int c,n,m,d,q,ans=999999999;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int k[505],w[500005],t[505][50005],x,y,a[505][50005];
bool vis[500005];
map<int,int>mp;
map<int,int>mp2;
void dfs(int x,int y,int c){
	if (mp[x]==mp[y]){
		ans=min(ans,c);
		return ;
	}
	int k=mp2[x];
	if (k==1){
		if (!vis[a[mp[x]][2]]){
			vis[a[mp[x]][2]]=1;
			c+=t[mp[x]][1]+t[mp[x]][2];
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			mp[a[i][j]]=i;
			mp2[a[i][j]]=j;
		}
	}
	
	while (q--){
		cnt=0;
		cin>>x>>y;//站x,站y 
		cnt+=w[x]+w[y];//地铁口 -> 站厅 
		int ax=mp[x],ay=mp[y];
		if (ax==ay){
			cnt+=t[ax][x]+t[ay][y];
			cout<<cnt<<endl;
		}
		else {
			vis[a[mp[x]][mp2[x]]]=1;
			dfs(x,y,cnt);
		}
	}
	return 0;
}

