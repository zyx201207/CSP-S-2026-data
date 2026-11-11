#include<bits/stdc++.h>
#define int long long
#define stp(x) fixed<<setprecision(x)
using namespace std;
const int N=2e6+10; 
int c,t;
int n,d,a[N];
int mn,k;
inline void dfs(int x,int y,int c){
	if(x==y){
		mn=min(mn,c);
		return;
	}
	int t=0;
	for(int i=x+1;i<=y;i++)if(a[i]-a[x]<=d)t=i;
	dfs(t,y,c+1);
}
inline void dfs2(int x,int y,int c){
	if(x==y){
		if(c==mn)k++;
		return;
	}
	if(k>2)return;
	if(c>mn)return;
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d)dfs2(i,y,c+1);
		else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mn=LONG_LONG_MAX,k=0;
				dfs(i,j,0);
				dfs2(i,j,0);
				if(k==2)cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
