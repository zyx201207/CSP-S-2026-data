#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int a[N],cnt,res,n,d;
void dfs(int x,int y,int c){
	if(x==y){
		if(res>c){
			res=c;
			cnt=1;
		}else if(res==c) cnt++;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d) dfs(i,y,c+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int hzx,t;
	cin>>hzx>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				res=1e9;
				cnt=0;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
