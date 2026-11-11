#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010;
struct h{
	int x,val;
};
int n,k,a[N],dis[N],cnt[N];
queue<h>q;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dis[j]=0x3f3f3f3f3f3f3f3f,cnt[j]=0;
			q.push({i,0});
			while(!q.empty()){
				int x=q.front().x;
				int val=q.front().val;
				q.pop();
				if(dis[x]<val)continue;
				if(dis[x]==val)
				cnt[x]++;
				else
				dis[x]=val,cnt[x]=1;
				for(int j=x;j<=n;j++){
					if(a[j]-a[x]<=k)
					q.push({j,dis[x]+1});
					else
					break;
				}
			}
			for(int j=i;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}else{
		int d=a[2]-a[1];
		if(k%d==0&&k>d&&k<=a[n]-a[1])
		cout<<n-2*k+1<<'\n';
		else
		cout<<"0\n";
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,T=0;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
