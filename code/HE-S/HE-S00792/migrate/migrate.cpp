#include <bits/stdc++.h>
#define int  long long
using namespace std;
int C,T;
int cnt,n,m,v,minn;
int x[5100];
void dfs(int now,int xx){
//	cout<<'|'<<now<<endl;
	if(now==v){
		if(minn>xx)minn=xx,cnt=1;
		else ++cnt;
		return ;
	}
	for(int i=now+1;i<=v;i++){
		if(x[i]-x[now]<=m)dfs(i,xx+1);
		else return;
	}
}
int tt[2001000];
void task(){
	while(T--){
		scanf("%lld%lld",&n,&m);
		int dd;
		for(int i=1;i<=n;i++){
			scanf("%lld",&tt[i]);
		}
		if(tt[2]-tt[1]>=m||tt[n]-tt[1]<m){cout<<0<<endl;continue;
		}
		dd=m/(tt[2]-tt[1]);
		cout<<max(n+1-2*dd,0ll)<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	if(11<=C&&C<=12){
		task();
		return 0-0;
	}
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				v=j,cnt=0,minn=0x3f3f3f3f;
				dfs(i,1);
//				cout<<minn<<" "<<cnt<<endl;
				if(cnt==2){
//					cout<<i<<" "<<j<<endl;
					++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
