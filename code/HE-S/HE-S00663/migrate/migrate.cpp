#include<bits/stdc++.h>
using namespace std;
#define int long long
//hope 30-50pts
const int N=2e6+10;
int pos[N],t,n,d;
int gsl(int st,int ed){
	int cnt=0;
	for(int nx=st+1;nx<=ed;nx++)
		if((pos[nx]-pos[st])>d){
			st=nx-1,cnt++;
			if((pos[nx]-pos[st])>d) return -1;
		}
	return cnt+(st!=ed);
}
int dfs(int sl,int st,int ed,int cnt){
	if(st==ed) return cnt==sl;
	int ans=0;
	for(int nx=st+1;nx<=ed;nx++){
		if((pos[nx]-pos[st])>d) break;
		ans+=dfs(sl,nx,ed,cnt+1);
	}
	return ans;
}
bool check(int st,int ed){
	return dfs(gsl(st,ed),st,ed,0)==2;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>pos[i];
		for(int i=1;i<=n-3;i++)
			for(int j=i+3;j<=n;j++)
				ans+=check(i,j);
		cout<<ans<<endl;
	}
	return 0;
} 
