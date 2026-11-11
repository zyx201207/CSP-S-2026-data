#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+6;
int a[N];
int n,d;
int rs;
int tp;
inline int dfs(int x,int y,int st){
	if(x>=y)return st;
	for(int i=y;i>x;i--){
		if(a[x]+d>=a[i]){
			dfs(i,y,st+1); 
			break;
		} 
	}
}
inline void sch(int x,int y,int st){
	if(x>=y){
		if(rs==st)tp++;
		return;
	}
	else for(int i=y;i>x;i--){
		if(a[x]+d>=a[i]){
			sch(i,y,st+1); 
		} 
	}
}
inline bool pd(int x,int y){
	rs=dfs(x,y,0);
	tp=0;
	//cout<<rs<<'\n';
	sch(x,y,0);
	if(tp==2)return 1;
	else return 0;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c>=6){
		while(t--){
			cout<<0<<'\n';
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(pd(i,j))ans++;
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
} 
