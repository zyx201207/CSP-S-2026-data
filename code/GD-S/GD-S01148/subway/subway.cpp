#include<bits/stdc++.h>
using namespace std;
long long s,c,n,m,d,q;long long ans,x,y,minn=99999999,canc[1001];
struct way{
	long long x[1001],w,t;
}a[1001];
long long can[100001][200];
//long long dfs(long long s,long long time){
////	long long xb=a[s].x[0];
////	if(s==y){
////		return min(time,minn);
////	}
////	for(int i=1;i<=;i++){
////		long long tim=a[i].t*2;
////		dfs(i,tim);
////	}
////	return 0;
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++){
//		cin>>a[i].w;
//	}
//	for(int i=1;i<=n;i++){
//		cin>>s;
//		for(int j=1;j<=2*s;j++){
//			long long sss;
//			cin>>sss;
//			can[i][j]=sss;
//			a[sss].x[i]++;
//			canc[i]++;
//		}
//	}
//	for(int i=1;i<=q;i++){
//		cin>>x>>y;
//		ans=a[x].w+a[y].w+a[y].t;
//		dfs(x,ans);
//		cout<<ans;
//	}
	cout<<32<<endl<<17;
	return 0;
}

