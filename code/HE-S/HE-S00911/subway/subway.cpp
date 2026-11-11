#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[600000],f[510][510],z[600000];
struct st{
	int u,v,w;
	bool operator<(const st yy)const{
		return v<yy.v;
	}
}a[500050];
int cnt;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t1,t2;
			cin>>t1>>t2;
			a[++cnt]=(st){i,t1,t2};
		}
	}
	sort(a+1,a+cnt+1);
	int l=0;
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}	
	for(int i=1;i<=cnt;i++){
		if(a[l].v!=a[i].v){
			l=i;
			z[a[i].v]=i;
		}
		for(int j=l;j<i;j++){
			int u1=a[j].u,u2=a[i].u;
			f[u1][u2]=min(f[u1][u2],a[j].w+a[i].w);
			f[u2][u1]=min(f[u2][u1],a[j].w+a[i].w);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int t1,t2;
		cin>>t1>>t2;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=z[t1];a[i].v==t1;i++){
			for(int j=z[t2];a[j].v==t2;j++){
				ans=min(a[i].w+a[j].w+f[a[i].u][a[j].u],ans);
			}
		}
		ans+=w[t1]+w[t2];
		cout<<ans<<endl;
	}
	return 0;
}
