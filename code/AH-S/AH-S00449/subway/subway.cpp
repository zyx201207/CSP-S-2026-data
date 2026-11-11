//subway
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],l[505][505],k,a,f,t,ans;
struct zhan{
	long long x,t;
}x,y;
vector<zhan> v[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a,&t);
			v[a].push_back((zhan){i,t});
		}
	}
	memset(l,0x3f,sizeof(l));
	for(int i=1;i<=n;i++)l[i][i]=0;
	for(int i=1;i<=m;i++){
		int p=v[i].size();
		for(int j=0;j<p;j++){
			x=v[i][j];
			for(int k=j+1;k<p;k++){
				y=v[i][k];
				if(l[x.x][y.x]>y.t+y.t){
					l[x.x][y.x]=x.t+y.t;
					l[y.x][x.x]=x.t+y.t;
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(l[i][j]>l[i][k]+l[k][j]){
					l[i][j]=l[i][k]+l[k][j];
					l[j][i]=l[i][k]+l[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans=0x3f3f3f3f3f3f3f3f;
		scanf("%lld%lld",&f,&t);
		int p=v[f].size(),q=v[t].size();
		for(int j=0;j<p;j++){
			x=v[f][j];
			for(int k=0;k<q;k++){
				y=v[t][k];
				if(ans>x.t+l[x.x][y.x]+y.t)ans=x.t+l[x.x][y.x]+y.t;
				//cout<<x.x<<' '<<x.t<<' '<<l[x.x][y.x]<<' '<<y.x<<' '<<y.t<<' '<<'\n';
			}
		}
		printf("%lld\n",ans+w[f]+w[t]);
	}
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
