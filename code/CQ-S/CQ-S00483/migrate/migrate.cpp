#include<bits/stdc++.h>
using namespace std;
int c,t,n,pre[2000005],nxt[2000005];
long long d,ans,f[2000005],g[2000005],h[2000005],x[2000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d,ans=pre[n+1]=0;
		for(int i=1;i<=n;i++) cin>>x[i],f[i]=g[i]=h[i]=pre[i]=nxt[i]=0;
		for(int i=1;i<n;i++){
			if(x[i+1]-x[i]>d) continue; 
			nxt[i]=max(i+1,nxt[i-1]);
			while(nxt[i]<n && x[nxt[i]+1]-x[i]<=d) nxt[i]++;
		}
		for(int i=n;i>1;i--){
			if(x[i]-x[i-1]>d) continue; 
			pre[i]=i-1;
			if(pre[i+1]) pre[i]=min(pre[i],pre[i+1]); 
			while(pre[i]>1 && x[i]-x[pre[i]-1]<=d) pre[i]--;
		}
		for(int i=1;i<=n;i++){
			if(nxt[i] && pre[nxt[i]]<=i) f[nxt[i]]++;
			if(nxt[i]>i+1 && pre[nxt[i]-1]<=i) g[nxt[i]]++;
			if(pre[i] && nxt[pre[i]]==i) f[i]+=f[pre[i]],h[i]+=h[pre[i]];
			if(pre[i] && nxt[pre[i]]>i) ans+=h[pre[i]];
			if(pre[i] && nxt[pre[i]]==i+1) g[i+1]+=f[pre[i]];
			if(pre[i] && nxt[pre[i]+1]==i) h[i]+=g[pre[i]+1];
			if(pre[i] && nxt[pre[i]+1]>i) ans+=g[pre[i]+1];
			ans+=h[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
