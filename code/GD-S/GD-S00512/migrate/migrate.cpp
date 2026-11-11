#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;
int n,d;
int L,R,ans;
int a[N+5];
int jp[N+5];
int f[N+5][2][4][4];
void prepare(){
	int p=0;
	for(int i=1;i<=n;++i){
		while(p+1<=n&&a[p+1]-a[i]<=d)
			++p;
		jp[i]=p;
	}
}
void calc(){
	for(int i=R;i>=L;--i){
		int j=jp[i];
		if(j==R)
			memset(f[i],0,sizeof f[i]);
		for(int y=1;y<=3;++y){
			int &res=f[i][0][0][y];
			res=0;
			if(y==2)
				res+=j-i;
			if(i+1==j)
				res+=f[j][0][0][y];
			else res+=f[j][1][y][y];
		}
		for(int x=1;x<=3;++x)
			for(int y=1;y<=3;++y){
				int &res=f[i][1][x][y];
				res=0;
				int p1=max(i,jp[i-2]),p2=jp[i-1],g1,g2;
				if(x+y==2)
					res+=p2-p1;
				if(y==2)
					res+=j-p2;
				if(p2+1<=j)
					g2=y;
				else if(p1+1<=j)
					g2=min(3ll,x+y);
				else g2=3;
				if(p2+1<=j-1)
					g1=y;
				else if(p1+1<=j-1)
					g1=min(3ll,x+y);
				else g1=3;
				if(i+1==j)
					res+=f[j][0][0][g2];
				else res+=f[j][1][g1][g2];
			}
	} 
	for(int i=L;i<=R;++i)
		ans+=f[i][0][0][1];
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	prepare();
	int lst=0;
	ans=0;
	for(int i=1;i<=n;++i)
		if(jp[i]==i){
			L=lst+1,R=i;
			calc();
			lst=i;
		}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
		solve();
	return 0;
}

