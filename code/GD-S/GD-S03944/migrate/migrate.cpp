#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,mi,res;
int a[2000007];
void dfs(int x,int to,int sum,int cnt){
	if(res>2)return;
//	cout<<x<<" "<<to<<" "<<sum<<" "<<cnt<<" \n";
	if(x==to&&sum==cnt){
		res++;
		return;
	}
	for(int i=x+1;a[i]<=a[x]+d&&i<=to;i++){
		dfs(i,to,sum+1,cnt);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				int sum=0;
				for(int i=u;i<v;){
					int it=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
					if(i==it)goto nexx;
					i=it;
					sum++;
				}
//				cout<<u<<" "<<v<<" "<<sum<<"!"<<"\n";
				res=0;
				dfs(u,v,0,sum);
				if(res==2)ans++;
				nexx:;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
