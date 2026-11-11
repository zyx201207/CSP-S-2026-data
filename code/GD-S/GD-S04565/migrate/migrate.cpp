#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e6+10;
int n,d,ls[N],nx[N],x[N],f[N][3];
void solve(){
	rep(i,1,n) cin>>x[i];
	int j=1;
	rep(i,1,n){
		while(j+1<=n&&abs(x[j+1]-x[i])<=d) ++j;
		nx[i]=j;
	}
	j=n;
	for(int i=n;i>=1;--i){
		while(j-1>=1&&abs(x[j-1]-x[i])<=d) --j;
		ls[i]=j;
	}
//	rep(i,1,n) cout<<nx[i]<<" ";
//	cout<<"\n";
	int ans=0;
	rep(i,1,n){
		int tot=0,now=i,f=0;
		rep(j,i+1,n){
			if(nx[now]==now) break;
			if(nx[now]<j){
				if(now!=i){
					if(nx[now-1]==nx[now]){
						++f;
						if(nx[now-2]==nx[now]) ++f;	
					}
				}
				now=nx[now];
			}
			if(nx[now]==now) break;
			int t=min(nx[now],j),tt=0;
			if(now!=i){
				if(nx[now-1]>=j){
					++tt;
					if(nx[now-2]>=j) ++tt;
				}
			}
			if(f+tt==1&&!(nx[now-1]==j&&ls[now-1]>i&&ls[now-1]<ls[now])){
//				if(i==2) cout<<f<<" "<<tt<<" "<<i<<" "<<j<<" "<<f<<" "<<now<<"\n";
				++tot;
			}
//			if(i==1) cout<<j<<" "<<f<<" "<<now<<"\n";
		}
//		cout<<tot<<" ";
		ans+=tot;
	}
	cout<<ans<<"\n";
}
void solve2(){
	rep(i,1,n){
		cin>>x[i];
		rep(j,0,2) f[i][j]=0;
	}
	int j=1;
	rep(i,1,n){
		while(j+1<=n&&abs(x[j+1]-x[i])<=d) ++j;
		nx[i]=j;
	}
	j=n;
	for(int i=n;i>=1;--i){
		while(j-1>=1&&abs(x[j-1]-x[i])<=d) --j;
		ls[i]=j;
	}
	int ans=0;
	for(int i=n-1;i>=1;--i){
		int t=nx[i],t0=f[t][0],t1=f[t][1];
		f[i][0]=t-i;
		if(t==i) continue;
		if(t-1==i){
			f[i][0]+=t0,f[i][1]+=t1;
			ans+=f[i][1];
			continue;
		}
		if(ls[nx[t]-1]<t&&ls[nx[t]-1]>i) t1-=(nx[nx[t]-1]-max(nx[t],nx[nx[t]-2]));
		if(nx[t-1]==nx[t]){
			if(nx[t-2]==nx[t]){
				1;
			}
			else{
				t0-=(nx[t-2]-t);
				f[i][1]+=t0;
			}
		}
		else{
			t0-=(nx[t-1]-t),t1+=(nx[t-1]-nx[t-2]);
			f[i][0]+=t0,f[i][1]+=t1;
		}
		ans+=f[i][1];
//		cout<<f[i][1]<<" ";
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=5000) solve();
		else solve2();
	}
	return 0;
} 
/*
0 1
6 3
0 1 2 3 4 7

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
ans:
1
2


0 1
6 2
-4 -3 -2 -1 3 6

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
ans:
0
1

*/
