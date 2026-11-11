#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,M=2e6+10;
int n,d,dis[N][N],u[N],cntt[N][N],cnt,a[N],maxn[M];
queue<int> q;
void init(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) dis[i][j]=1e18;
		dis[i][i]=0;cntt[i][i]=1;
	}
	return ;
}
void spfa(int id){
	q.push(id);
	while (!q.empty()){
		int x=q.front();
		q.pop();
		u[x]=0;
		for (int i=x+1;i<=n;i++){
			if (a[i]>a[x]+d) break;
			if (dis[id][i]==dis[id][x]+1){
				cntt[id][i]+=cntt[id][x];
			}
			if (dis[id][i]>dis[id][x]+1){
				dis[id][i]=dis[id][x]+1;
				cntt[id][i]=cntt[id][x];
				if (!u[i]){
					u[i]=1;
					q.push(i);
				}
			}
		}
	}
//	cout<<id<<": ";
	for (int i=id+1;i<=n;i++){
//		cout<<dis[id][i]<<"&"<<cntt[id][i]<<" ";
		if (cntt[id][i]==2) cnt++;
	} 
//	cout<<endl;
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ID,T;
	scanf ("%lld%lld",&ID,&T);
	while (T--){
		cnt=0;
		scanf ("%lld%lld",&n,&d);
		for (int i=1;i<=n;i++) scanf ("%lld",&a[i]);
		if (ID==13||ID==14){
			int id=0;
			for (int i=1;i<=n;i++)
				if (a[n]-a[i]<=d&&a[i]-a[1]<=d){
					id=i;
					break;
				}
			int r=0;
			for (int l=1;l<=n;l++){
				while (a[r+1]<=a[l]+d&&r<n) r++;
				maxn[l]=r;
			}
			for (int l=1;l<=n;l++){
				if (maxn[l]<=id) continue;
				if (id==maxn[l]&&id-2>0&&a[n]-a[id-2]>d) cnt+=n-maxn[id-2];
				if (id+1==maxn[l]&&id-1>0&&a[n]-a[id-1]>d) cnt+=n-maxn[id-1];
				if (l==id||r>=id+2) break;
			}
			printf ("%lld\n",cnt);
		}
		else{
			init();
			for (int i=1;i<=n;i++) spfa(i);
			printf ("%lld\n",cnt);
		}
		
	}
	return 0;
}

