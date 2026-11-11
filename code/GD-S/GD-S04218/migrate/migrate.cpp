#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
int x[N];
int a[N],b[N];
int nxt[N],lst[N];
int f[N],lt[N];
int e[N],cnt;
int ll[N],rr[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(f,0,sizeof(f));
		memset(e,0,sizeof(e));
		memset(nxt,0,sizeof(nxt));
		memset(lst,0,sizeof(lst));
		cnt=0;
		cin>>n>>d;
		ll[0]=1;
		rr[n+1]=n;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]>d)ll[i]=i;
			else ll[i]=ll[i-1];
		}
		for(int i=n;i>=1;i--){
			if(x[i+1]-x[i]>d)rr[i]=i;
			else rr[i]=rr[i+1];
		}
		for(int i=1;i<=n;i++){
			nxt[i]=upper_bound(x+1+i,x+1+n,x[i]+d)-1-x;
			lst[i]=lower_bound(x+1,x+1+i,x[i]-d)-x;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			f[i]=nxt[nxt[i]-1];
			
//			cout<<f[i]-(nxt[nxt[i]-2])<<" "<<lst[nxt[i]+1]-i<<"\n";
			if(lst[f[i]]!=nxt[i]-1||f[i]-i<3)f[i]=-1;
			else lt[f[i]]=i,e[++cnt]=i/*,ans+=max((long long)0,(f[i]-(nxt[nxt[i]-2]))*(lst[nxt[i]+1]-i))*/;
		}
		e[cnt+1]=n+1;
		f[n+1]=n+1;
		for(int i=1;i<=cnt;i++){
			int x=e[i],y=f[e[i]];
			int l=max(ll[x],e[i-1]+1),r=min(rr[y],f[e[i+1]]-1);
//			x--,y++;
			ans+=max((long long)0,(x-l+1)*(r-y+1));
//			cout<<ll[i]<<" "<<rr[i]<<"\n";
		}
		cout<<ans<<"\n";
//		cout<<rr[5];
	}
	return 0;
}

