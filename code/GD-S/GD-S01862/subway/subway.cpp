#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[5000005],a[505][50005],t[505][50005],st,ed;
long long minn=1e9+100,sum=0;
bool bb[500005],b[505][50005];
void dfs(int x){
	if(x==ed){
		minn=min(minn,sum);
		return ;
	}
	while(x!=ed){
		for(int i=1;i<=n;i++){
			if(b[i][x]==true&&bb[x]==true){
				sum+=t[i][x];
				bb[x]=false;
				dfs(a[i][x+1]);
				bb[x]=true;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(bb,true,sizeof(bb));
	memset(b,true,sizeof(b));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			b[i][x]=true;
			a[i][j]=x;
			t[i][x]=y;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st>>ed;
		minn=1e9+100;
		sum=0;
		dfs(st);
		cout<<minn+w[st]+w[ed]<<endl;
	}
	return 0;
}
