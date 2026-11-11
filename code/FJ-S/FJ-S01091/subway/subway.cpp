#include<bits/stdc++.h>
using namespace std;
vector<int> g[505];
long long c,n,m,d,q,w[500005],t[25][500005],sps,s=99999999,aans=99999999,tt;
bool flag[500005],ml[25][500005];
void dfs(int st,int ans,int l){
	if(st==sps){
		tt=l;
		s=min((int)s,ans);
		return;
	}
	if(flag[st])	return;
	for(int i=0;i<g[st].size();i++){
		flag[st]=1;
		int ns=ans;
		int book=-1;
		for(int j=1;j<=m;j++)
			if(ml[j][g[st][i]]==1&&ml[j][st]==1){
				book=j;
				break;
			}
		int nl=l;
		if(book!=l&&book!=-1)	ns=ns+t[l][st]+t[book][st],nl=book;
		dfs(g[st][i],ns,nl);
		flag[st]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,x,y,cx,cy;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>cx>>cy;
			g[x].push_back(cx);
			g[cx].push_back(x);
			t[i][cx]=cy;
			ml[i][cx]=1;
			x=cx,y=cy;
		}
	}
	while(q--){
		int sts;
		cin>>sts>>sps;
		aans=99999999;
		s=99999999;
		for(int i=1;i<=n;i++){
			if(ml[i][sts]==0)	continue;
			memset(flag,0,sizeof(flag));
			dfs(sts,0,i);
			s=s+w[sts]+w[sps]+t[i][sts]+t[tt][sps];
			aans=min(aans,s);
		}
		cout<<aans<<endl;
	}
	return 0;
}
