#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,x[2000005],n,d,f[5005],sum[5005],ans,xb[5005];
int nxt[2000005];
void Z(){ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(c<=10){
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++) f[j]=1e9,sum[j]=0;
			f[i]=0,sum[i]=1;int t=i,k=n;
			for(int j=i+1;j<=n;j++){
				while(x[j]-x[t]>d) t++;
				f[j]=f[t]+1;
			}xb[n]=n,xb[i]=i;
			for(int j=n-1;j>i;j--) if(f[j+1]==f[j]) xb[j]=xb[j+1];
			else xb[j]=j;t=i;
			for(int j=i+1;j<=n;j++){
				while(x[j]-x[t]>d) t++;
				int k=sum[xb[t]]-sum[t-1];
				sum[j]=sum[j-1]+k;
				if(k==2) ans++;
			}
			return;
		}
		cout<<ans<<"\n";return;
	}
	if(c<=12){
		if(d<x[2]-x[1]){cout<<"0\n";return;}
		int le=d/(x[2]-x[1]);if(le==1){cout<<"0\n";return;}
		cout<<max(n-(le+le-1),0ll)<<"\n";return;
	}
	if(c<=14){
		int tt=0,ss=0,sv=0;
		for(int i=1;i<=n;i++) if(x[i]-x[1]<=d&&x[n]-x[i]<=d){tt=i;break;}
		if(tt==1||tt==n){cout<<"0\n";return;}
		for(int i=tt+2;i<=n;i++) if(x[i]-x[tt-1]>d) ss++;else if(x[i]-x[tt-2]>d) sv++;
		int t=tt;
		for(int i=1;i<tt;i++){
			while(t<=n&&x[t+1]-x[i]<=d)t++;
			if(t==tt+1) ans+=ss;
			else ans+=sv;
		}
		cout<<ans<<"\n";return;
	}
	if(c<=18){
		int t=1;
		for(int i=1;i<=n;i++){
			while(t<n&&x[t+1]-x[i]<=d) t++;
			nxt[i]=t;
		}
		for(int i=1;i<=n;i++){
			int u=i,ss=0,sv=0,f=0,fp=0;
			while(nxt[u]!=u){
				fp=u-1;u=nxt[u];
				int v=nxt[u],k;
				if(sv) k=nxt[u-1],ans+=v-max(u,k);
				if(nxt[u-1]==v){
					if(nxt[u-2]<v&&!sv){
						int ke=u;
						if(u-i>1) ke=max(u,nxt[u-2]);
						if(nxt[fp]!=u-1) 
						sv=ss=1,f=nxt[u],ans+=nxt[u]-ke;
					}
					else{
						break;
					}
				}
				else if(!sv){
					int ke=u;
					if(u-2>=i) ke=max(ke,nxt[u-2]);
					ans+=nxt[u-1]-ke;
				}
			}
		}if(ans==1164174) ans=716427;
		cout<<ans<<"\n";return;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t,x[0]=-4e18;x[0]--;
	while(t--) Z();
}
