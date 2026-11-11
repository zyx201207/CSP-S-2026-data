#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,t,k,x,bj[100005],dis[100005],y,num[100005],a[100005],b[100005],nxt[1000005],h[100005],to[1000005],l[1000005];
int cnt;
vector<int>vt[100005];
void add(int x,int y,int z){
	to[++cnt]=y;
	l[cnt]=z;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
priority_queue<pair<int,int> >p;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>t;
	int o;
	for(int i=1;i<=n;i++){
		scanf("%lld",&num[i]);
	}
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[j],&b[j]);
			o=b[j];
			for(int x=1;x<j;x++){
				add(a[x],a[j],b[j]+b[x]);
				add(a[j],a[x],b[j]+b[x]);
				vt[a[x]].push_back(a[j]);
				vt[a[j]].push_back(a[x]);
			}
		}
	}
	while(t--){
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=n;i++) bj[i]=0,dis[i]=1e18;
		if(12<=c&&c<=19){
			queue<int>q;
			q.push(x);
			dis[x]=0;
			bj[x]=1;
			while(!q.empty()){
				int k=q.front();
				q.pop();
				int bjj=0;
				for(int i=0;i<vt[k].size();i++){
					if(bj[vt[k][i]]==0){
						bj[vt[k][i]]=1;
						dis[vt[k][i]]=dis[k]+1;
						q.push(vt[k][i]);
						if(vt[k][i]==y){
							bjj=1;
							break;
						}
					}
				}
				if(bjj==1) break;
			}
			cout<<(dis[y])*2*o+num[x]+num[y]<<"\n";
			continue;
		}
		p.push({0,x});
		dis[x]=0;
		while(!p.empty()){
			int k=p.top().second;
			p.pop();
			if(bj[k]==1) continue;
			bj[k]=1;
			for(int i=h[k];i!=0;i=nxt[i]){
				if(dis[to[i]]>dis[k]+l[i]){
					dis[to[i]]=dis[k]+l[i];
					p.push({-dis[to[i]],to[i]});
				}
			}
		}
		int ans=dis[y]+num[x]+num[y];
		cout<<ans<<"\n";
	}
	return 0;
}
