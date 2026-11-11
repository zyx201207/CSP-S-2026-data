#include<bits/stdc++.h>
using namespace std;
int n,m,c,q,d,b[505],a[505][505][2],w[505],f[505],t[500005][505],ans1;
struct s{
	int u,v;
};
void bfs(int x,int y){
	queue<s> q;
	q.push({x,0});
	bool fl=0;
	f[x]=1;
	while(!q.empty()){
		s ss=q.front();
	//	cout<<ss.u<<ss.v<<' ';
		q.pop();
		if(ss.u==y)ans1=ss.v;
		for(int i=1;i<=b[ss.u];i++){
	//		cout<<a[ss.u][i][0]<<' ';
			if(f[a[ss.u][i][0]]==0){
				f[a[ss.u][i][0]]=1;
				q.push({a[ss.u][i][0],ss.v+t[a[ss.u][i][1]][a[ss.u][i][0]]});
			//	cout<<a[ss.u][i][0]<<ss.v<<t[a[ss.u][i][1]][a[ss.u][i][0]]<<' ';
			}
			if(fl==0){
			    f[a[ss.u][i][0]]=1;
			    int aaa=t[a[ss.u][i][1]][ss.u]+t[a[ss.u][i][1]][a[ss.u][i][0]];
				q.push({a[ss.u][i][0],aaa});
			}
		}
		fl=1;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,x;i<=n;i++){
		int aa,bb;
		cin>>x;
		cin>>aa;
		cin>>t[i][aa];
		for(int j=2;j<=x;j++){
	    cin>>bb;
	    b[aa]++;
	    b[bb]++;
	    a[aa][b[aa]][0]=bb;
	    a[bb][b[bb]][0]=aa;
	    a[aa][b[aa]][1]=i;
	    a[bb][b[bb]][1]=i;
	    aa=bb;
	    cin>>t[i][aa];
		}
	}
	while(q--){
		int x,y,ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		bfs(x,y);
		ans+=ans1;
		cout<<ans<<endl;
		ans1=0;
		for(int i=1;i<=m;i++)f[i]=0;
	}
	return 0;
}
