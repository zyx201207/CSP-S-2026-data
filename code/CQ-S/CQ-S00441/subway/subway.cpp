#include<bits/stdc++.h>//嗯对这个暴力打了我一个小时 
using namespace std;
int f,n,m,d,q;
struct x{
	long long t,w,id;//t终点,w权值（时间）,id第几号线
};
vector<x>a[200005];
int w[200005];
long long an[505][200005];
int e[505][200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>f>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int now,la;
		for(int j=1;j<=k;j++){
			cin>>now;
			int w;
			cin>>w;
			e[i][now]=w;
			if(j==1){
				la=now;
				continue;
			}
			a[now].push_back({la,w,i});
			a[la].push_back({now,w,i});
			la=now;
		}
	}
	while(q--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)an[i][j]=LONG_LONG_MAX;
		}
		int xx,y;
		cin>>xx>>y;
		queue<x>b;
		for(int i=1;i<=n;i++){
			if(e[i][xx]!=0)b.push({xx,e[i][xx],i});
		} 
		for(int i=1;i<=n;i++){
			if(e[i][xx]!=0)an[i][xx]=e[i][xx];
		}
		while(!b.empty()){
			x c=b.front();
			b.pop();
			if(c.w>an[c.id][c.t]){
				continue;
			}
			for(auto yy:a[c.t]){
				if(yy.id==c.id){
					if(an[yy.id][yy.t]>c.w){
						an[yy.id][yy.t]=c.w;
						b.push({yy.t,an[yy.id][yy.t],yy.id});
					}
				}
				else {
					if(an[yy.id][yy.t]>c.w+e[c.id][c.t]+e[yy.id][c.t]){
						an[yy.id][yy.t]=c.w+e[c.id][c.t]+e[yy.id][c.t];
						b.push({yy.t,an[yy.id][yy.t],yy.id});
					}
				}
			}
		}
		long long ans=LONG_LONG_MAX;
		for(int i=1;i<=n;i++){
			ans=min(ans,an[i][y]+e[i][y]);
		}
		cout<<ans+w[xx]+w[y]<<endl;
	}
	return 0;
}
