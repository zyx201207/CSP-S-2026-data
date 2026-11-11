#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
int c,t,n,d,a[2000010],f[2000010],g[2000010],cntp[2000010],cnts[2000010],ans,nxt[2000010],pre[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			f[i]=g[i]=0;
			cntp[i]=cnts[i]=0;
		}
		int j=n;
		for(int i=n;i>0;i--){
			while(j>0&&a[i]+d<a[j]){
				j--;
			}
			nxt[i]=j;
			if(i!=j)cntp[j]++;
		}
		j=1;
		for(int i=1;i<=n;i++){
			while(j<=n&&a[j]+d<a[i]){
				j++;
			}
			pre[i]=j;
			if(i!=j)cnts[j]++;
		}
		for(int i=1;i<=n;i++){
			f[i]=cntp[i];
			if(pre[i]!=i&&nxt[pre[i]]==i){
				f[i]+=f[pre[i]];
			}
		}
		for(int i=n;i>0;i--){
			g[i]=cnts[i];
			if(nxt[i]!=i&&pre[nxt[i]]==i){
				g[i]+=g[nxt[i]];
			}
		}
		for(int i=1;i<n;i++){
			int ps=cntp[i+1],ss=cnts[i];
			if(nxt[i]==i+1)ps--;
			if(pre[i+1]==i)ss--;
			if(pre[i+1]!=i+1&&nxt[pre[i+1]]==i+1&&pre[i]==pre[i+1]){
				ps+=f[pre[i]];
			}
			if(nxt[i]!=i&&pre[nxt[i]]==i&&nxt[i+1]==nxt[i]){
				ss+=g[nxt[i]];
			}
			ans+=ps*ss;
		}
		cout<<ans<<endl;
	}
	return 0;
}
int read(){
	int s=0,sg=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')sg=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*sg;
}