#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e3;

int C,T;
int n,d;
int ans;
int x[N+5];
int p[N+5];
int f[N+5];
int b[N+5];
int cnt[N+5];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			p[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
		}
		for(int now=1;now<=n;now++){
			memset(cnt,0,sizeof(cnt));
			memset(f,0x3f3f3f3f,sizeof(f));
			memset(b,0x3f3f3f3f,sizeof(b));
			f[now]=0;
			cnt[now]=1;
			cnt[now+1]=-1;
			int tmp=now+1;
			for(int i=now;i<=n;i++){
				for(int j=tmp;j<=p[i];j++){
					f[j]=f[i]+1;
				}
				tmp=p[i]+1;
			}
			for(int i=now+1;i<=n;i++){
				if(f[i]<=n) b[f[i]]=min(b[f[i]],i);
			}
			for(int i=now;i<=n;i++){
				cnt[i]+=cnt[i-1];
				if(f[i]>n||b[f[i]+1]>n) continue;
				cnt[b[f[i]+1]]+=cnt[i];
				cnt[p[i]+1]-=cnt[i];
			} 
			for(int i=now+1;i<=n;i++){
				if(cnt[i]==2) ans++;
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
