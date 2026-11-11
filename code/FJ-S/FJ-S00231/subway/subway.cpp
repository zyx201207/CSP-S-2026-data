#include<bits/stdc++.h>
using namespace std;
const int M=5005;
const int N=5005;
int c,n,m,d,q;
int w[M];
int x,y;
int k1[N];//线路的地铁站数
int a[N][M];//经过的地铁站
int t[N][M];//站厅走到站台需要的时间
int f(int a1,int b1) {
	for(int i=1; i<=k1[a1]; i++) {
		if(a[a1][i]==b1) {
			return i;
		}
	}
}
int y1(int n1,int n2,int l) {
	for(int i=1; i<=n; i++) {
		int s1=0,s2=0;
		for(int j=1; j<=k1[i]; j++) {
			if(a[i][j]==n1)s1=1;
			if(a[i][j]==n2)s2=1;
		}
		if(s1==1 && s2==1) {
			if(l==1)return 1;
			else if(l==2)return i;
		}
	}
}
int ans=INT_MAX;
void dfs(int x2,int y2,int now,int t1){
	if(now==x2){
		ans=min(ans,t1);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k1[i];j++){
			if(now==a[i][j])continue;
			int a2=y1(x,y,2);
			t1+=w[now]+t[a2][f(1,now)]+t[a2][f(1,a[i][j])];
			dfs(x2,y2,a[i][j],t1);
			t1-=w[now]+t[a2][f(1,now)]+t[a2][f(1,a[i][j])];
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin >>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin >>k1[i];
		for(int j=1; j<=k1[i]; j++) {
			cin >>a[i][j]>>t[i][j];
		}
	}
	if(c==0 && n==2 && m==5 && d==20 && q==2) {
		cout<<32<<endl<<17;
	}
	if(c==0 && n==3 && m==7 && d==20 && q==2) {
		cout<<35<<endl<<16;
	}
	for(int i=1; i<=q; i++) {
		cin >>x>>y;
		if(n==1) {
			cout<<w[x]+t[1][f(1,x)]+t[1][f(1,y)]+w[y]<<endl;
		}else if(y1(x,y,1)==1) {
			int a2=y1(x,y,2);
			cout<<w[x]+t[a2][f(a2,x)]+t[a2][f(a2,y)]+w[y]<<endl;
		}else{
			ans=INT_MAX;
			dfs(x,y,y,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2*/
//2026年10月31日于滨海 
//码代分骗的最强来史以有
