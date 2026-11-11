#include<bits/stdc++.h>
using namespace std;
#define int long long
const int xxxx=2147483600;
int c,n,m,d,q;
vector<int> w;
vector<int> k;
int a[505][50005];
bool aaa[505][50005];
int t[505][50005];
int x,y,ans=xxxx;
void dfs(int xx,int maxx,int ii,int ccc){
	if(aaa[ii][xx])return;
	if(ccc>8)return;
	else ccc++;
	if(xx==y){
		if(maxx<ans)ans=maxx;
		return;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k[ii];j++){
			aaa[i][j]=1;
			dfs(a[i][j],maxx+t[i][j],ii,ccc);
			aaa[i][j]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	w.resize(m);
	k.resize(n);
	for(int i=0;i<m;i++)scanf("%lld",&w[i]);
	for(int i=0;i<n;i++){
		scanf("%lld",&k[i]);
		for(int j=0;j<k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
	}
	for(int i=0;i<q;i++){
		ans=xxxx;
		scanf("%lld%lld",&x,&y);
		dfs(x,w[x],0,0);
		printf("%d\n",ans);
	}
	return 0;
}

