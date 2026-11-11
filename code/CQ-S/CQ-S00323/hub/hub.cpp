#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int>to[1000005];
bool us[1000005];
int fa[1000005],ans,bns;
int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int fid(int k,int f,int d){
	if(us[k])return d;
	int len=to[k].size(),res=n+1;
	for(int i=0;i<len;i++){
		int v=to[k][i];
		if(v!=f)res=min(res,fid(v,k,d+1));
	}return res;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;ans=n;
		for(int i=1;i<=n;i++)to[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}for(int p=1;p<(1<<n);p++){
			int cnt=0;
			for(int i=0;i<n;i++){
				if(p&(1<<i)){
					us[i+1]=1;
					cnt++;
				}else us[i+1]=0;
			}if(cnt==k){
				for(int i=1;i<=n;i++)fa[i]=i;
				for(int i=1;i<=n;i++){
					int len=to[i].size();
					for(int l=0;l<len;l++){
						int j=to[i][l];
						if(us[i]&&us[j]&&find(i)!=find(j))cnt--;fa[find(i)]=find(j);
					}
				}if(cnt<=2){
					bns=0;
					for(int i=1;i<=n;i++)bns=max(bns,fid(i,0,0));
					ans=min(ans,bns);
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
}/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
