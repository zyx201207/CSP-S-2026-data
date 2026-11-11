#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long a,t;
};
vector<stu> g[500010];
long long n,m,c,d,q,u[500010],k[500010],x,y,sx,ex,mn=0x3f3f3f3f3f3f3f3f,sum,vis[500010];
void dp(long long qx,long long sum){
	if(qx==ex){
		mn=min(mn,sum);
		return ;
	}
	vis[qx]=1;
	for(int i=0;i<k[qx];i++){
		stu h=g[qx][i];
		if(!vis[h.a]){
			vis[h.a]=1;
			//cout<<h.a<<" "<<g[qx][i-1].t<<endl;
			dp(h.a,sum+h.t+g[qx][i-1].t);
			vis[h.a]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&u[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld %lld",&x,&y);
			g[i].push_back({x,y});
		}
	}
	//cout<<g[2][0].t<<endl;
	for(int i=1;i<=q;i++){
		cin>>sx>>ex;
		sum=0;
		mn=0x3f3f3f3f3f3f3f3f;
		sum+=u[sx]+u[ex];
		dp(sx,sum);
		cout<<mn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
