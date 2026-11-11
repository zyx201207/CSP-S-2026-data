#include<bits/stdc++.h>
using namespace std;
#define int long long
const int L=2e6+5;
int n,c,q,d,x[L],ans;
int find(int l,int r){
	int res=n+1;
	if(l==r) return 1;
//	cout<<l<<' '<<r<<endl;
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]<=d) res=min(res,find(i,r));
	}
	if(res<n&&res>0) return res+1;
	else return -1;
}
int dfs(int l,int r,int mx,int now){
	int res=0;
	if(l==r&&now==mx) return 1;
	if(now>=mx) return 0;
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]<=d){
			res+=dfs(i,r,mx,now+1);
		}
		else break;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int mx=find(i,j);
				if(mx<0) break;
				int num=dfs(i,j,mx,1);
				if(num==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
