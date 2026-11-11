#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5009;
int c,t,n,a[N],dis[N][N],b[N],tr[N],d;
int fg[N][N];
int qry(int *a,int n){
//	cerr<<"qry: "<<n<<"\n";
	for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) dis[i][j]=0,fg[i][j]=0;
	for(int i=1;i<=n;i++) tr[i]=(upper_bound(a+1,a+n+1,a[i]+d)-a)-1;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(tr[j]>=i) dis[j][i]=1;
			else dis[j][i]=dis[tr[j]][i]+1;
//			cout<<j<<" "<<i<<" "<<dis[j][i]<<" dis\n";
		}
	}
	int res=0;
	for(int j=1;j<=n;j++){
		for(int i=j-1;i>=1;i--){
			if(dis[i][j]==1) continue;
			int x=tr[i];
			x=min(x,j);
			if(fg[x][j]==-1){
				fg[i][j]=-1;
				continue;
			}
			if(dis[x][j]==dis[x-1][j]&&fg[x][j]&&x-1>=0){
				fg[i][j]=-1;
				continue;
			}
			if(dis[x][j]==dis[x-1][j]&&!fg[x][j]&&x-1>=0) fg[i][j]=1;
			if(dis[x][j]!=dis[x-1][j]&&fg[x][j]==1) fg[i][j]=1;
			if(dis[x][j]==dis[x-1][j]&&dis[x-1][j]==dis[x-2][j]&&x-2>=0){
				fg[i][j]=-1;
				continue;
			}
		}
		for(int i=1;i<j;i++) if(fg[i][j]==1) res++;
	}
	return res;
}
const int M=2e6+9;
int dis2[M];
bool fg2[M];
int qry2(int *a,int n){
	//	cerr<<"qry: "<<n<<"\n";
	for(int j=0;j<=n+1;j++) dis2[j]=0,fg2[j]=0;
	for(int i=1;i<=n;i++) tr[i]=(upper_bound(a+1,a+n+1,a[i]+d)-a)-1;
	int i=n;
		for(int j=i-1;j>=1;j--){
			if(tr[j]>=i) dis2[j]=1;
			else dis2[i]=dis2[tr[j]]+1;
//			cout<<j<<" "<<i<<" "<<dis[j][i]<<" dis\n";
		}
	int res=0;
	int j=n;
		for(int i=j-1;i>=1;i--){
			if(dis2[i]==1) continue;
			int x=tr[i];
			x=min(x,j);
			if(fg2[x]==-1){
				fg2[i]=-1;
				continue;
			}
			if(dis2[x]==dis[x-1][j]&&fg2[x]&&x-1>=0){
				fg2[i]=-1;
				continue;
			}
			if(dis2[x]==dis2[x-1]&&!fg2[x]&&x-1>=0) fg2[i]=1;
			if(dis2[x]!=dis2[x-1]&&fg2[x]==1) fg2[i]=1;
			if(dis2[x]==dis2[x-1]&&dis2[x-1]==dis2[x-2]&&x-2>=0){
				fg2[i]=-1;
				continue;
			}
		}
	for(int i=1;i<j;i++) if(fg2[i]==1) res+=i;
	return res;
}
void solve(){
	cin>>n>>d;
	int pre=1,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if((a[i]+d<a[i+1])||i==n){
	//		cout<<"init: "<<i<<"\n";
			int cnt=0;
			for(int j=pre;j<=i;j++) b[++cnt]=a[j];
			ans+=qry(b,cnt),pre=i;
		}
	}
	cout<<ans<<"\n";
}
void solve2(){
	cin>>n>>d;
	int pre=1,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if((a[i]+d<a[i+1])||i==n){
	//		cout<<"init: "<<i<<"\n";
			int cnt=0;
			for(int j=pre;j<=i;j++) b[++cnt]=a[j];
			ans+=qry2(b,cnt),pre=i;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/
/*
0 1
5 2
1 2 3 4 5
*/
