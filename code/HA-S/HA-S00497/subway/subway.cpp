#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long c,n,m,d,q,w[N],a[N][N],t[N][N],num,k[N],xx[N],yy[N],flag[110][110];
long long maxn;

void dfs(long long nowx,long long nowy,long long end,long long sum,long long o){
	if(flag[nowx][nowy]) return;
	flag[nowx][nowy]=1;
	maxn=max(maxn,o);
	xx[o]=nowx;
	yy[o]=nowy;
	if(sum>num) return;
	if(nowy==end) {
		num=min(num,sum);
	//	cout<<sum<<endl;
		return ;
	}
	for(int i=1;i<=k[nowx];i++){
		dfs(nowx,i,end,sum+t[nowx][i],o+1);
	}
	for(int i=1;i<=n;i++){
		dfs(i,nowy,end,sum+t[i][nowy],o+1);
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
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		memset(flag,0,sizeof(flag));
		memset(xx,0,sizeof(yy));
		maxn=0;
		memset(yy,0,sizeof(yy));
		long long x,y;
		cin>>x>>y;
		num=100;
		long long ans=0;
		dfs((long long)x,(long long)x,(long long)y,(long long)0,(long long)0);
	//	cout<<w[x]+w[y]+num+a[x][x]<<endl;
	long long p=0;
		for(long long j=0;j<=maxn;j++){
			ans+=t[xx[j]][yy[j]];
//			cout<<xx[j]<<" "<<yy[j]<<"    "<<ans-p<<endl;
			p=ans;
		}
		cout<<ans+w[x]+w[y];
		cout<<endl;
	}
	return 0;
}
