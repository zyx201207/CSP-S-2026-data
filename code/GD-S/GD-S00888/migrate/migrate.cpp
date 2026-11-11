#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=2e6+5;
int n,a[N],d;
bool vis[N];
void solve();
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,c;
	cin>>c>>T;
//	if(T==0) T++;
	while(T--){
		solve();
	}
	return 0;
}
struct data{
	int x,y;
};
void solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=d*2;i<=n;i++){
		int cnt=0,t=0;
		for(int j=i-d*2+1;j<=i;j++){
			queue<data> q;
			q.push({a[j],0});
			vis[a[j]]=1;
			while(!q.empty()){
				int x=q.front().x;
				int y=q.front().y;
				q.pop();
				if(x==a[i]){
					cnt++;
					vis[x]=0;
					continue;
				} 
				for(int k=min(x+d,n);k<=n;k++){
					if(!vis[k]){
						vis[k]=1;
						q.push({a[k],y+1});
					}
				}
			}
			cout<<cnt<<'\n';
		}
		if(cnt==2) ans++;
	}
	cout<<ans<<'\n';
}
