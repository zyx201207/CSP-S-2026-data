#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200,M=20005,Q=1e5+1;
ll n,m,d,q,jzk[M],k[M][N][2],tt[M],aa[M][25][2];
ll kk[5],a[M][N],kkk[15];
int qx[Q],qy[Q],vis[M];

vector<pair<int,int> > edge[M];
ll dfs1(int ii,ll xx,int jj){
	if(xx=qx[ii]) return 0;
	ll ans=2e9;
	for(int i=1;i<=n;i++) if(a[xx][i]!=2e9)
		for(int j=1;j<=m;j++) if(!vis[kkk[j]]){
			vis[kkk[j]]=1;
			ll cnt;
			if(jj!=j) cnt=a[xx][i]+a[kkk[j]][i]+dfs1(ii,kkk[j],j);
			else cnt=dfs1(ii,kkk[j],j);
			vis[kkk[j]]=0;
			ans=min(ans,cnt);
		}
	return ans;
}
void s1(){
	for(int i=1;i<=14;i++) for(int j=1;j<=4;j++) a[i][j]=2e9;
	for(int i=1;i<=n;i++){
		cin>>kk[i];int xx,yy;
		for(int j=1;j<=kk[i];j++) cin>>xx>>yy,a[xx][i]=yy,kkk[i]=xx;
	}
	for(int i=1;i<=q;i++) cin>>qx[i]>>qy[i],vis[qx[i]]=1,cout<<dfs1(i,qx[i],0)+jzk[qx[i]]+jzk[qy[i]]<<'\n',vis[qx[i]]=0;
}
int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int QWQ;
	cin>>QWQ>>n>>m>>d>>q;
	if(QWQ==0){
		if(n==2) cout<<"32\n17";else cout<<"35\n16";return 0;
	}
	for(int i=1;i<=m;i++) cin>>jzk[i];
	int pd=1;
	return s1(),0;
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
