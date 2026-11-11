#include <bits/stdc++.h>
#define name "migrate"
using namespace std;
const int N=2000007;
typedef long long li;
li l[N],r[N],g[N],f[N][2],x[N];
int main(){
	freopen(name".in","r",stdin);
	freopen(name".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t-->0){
		li n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=0;i<=n;i++) f[i][0]=f[i][1]=g[i]=0;
		int qwq=1;
		for(int i=1;i<=n;i++){
			while(qwq<i&&x[i]-x[qwq]>d) qwq++;
			l[i]=qwq;
		}
		qwq=n;
		for(int i=n;i;i--){
			while(qwq>i&&x[qwq]-x[i]>d) qwq--;
			r[i]=qwq;
		}
		for(int i=1;i<=n;i++) if(r[i]>i) g[r[i]]++;
		for(int i=1;i<=n;i++){
			f[i][0]=g[i];
			if(l[i]<i&&r[l[i]]==i) f[i][0]+=f[l[i]][0];
			f[i][1]=0;
			if(l[i]+1<i&&r[l[i]+1]==i) {
				f[i][1]+=f[l[i]+1][0];
			}
			if(l[i]<i&&r[l[i]]==i) f[i][1]+=f[l[i]][1];
		}
		/*for(int i=2;i<=n;i++) if(r[i-1]==r[i]&&r[i]!=i) g[i]++;
		for(int i=3;i<=n;i++) if(r[i-2]==r[i]&&r[i]!=i) g[i]++;
		for(int i=1;i<=n;i++){
			if(r[i]==i) continue;
			if(g[r[i]]==0||r[i]==i+1) f[r[i]][0]+=f[i][0]+1,f[r[i]][1]+=f[i][1];
			else if(g[r[i]]==1||r[i]==i+2) f[r[i]][1]+=f[i][0]+1;
		}*/
		li ans=0;
		/*for(int i=3;i<=n;i++){
			ans+=1ll*f[i][1]*(r[i]-max(1ll*i,r[i-1]));
			ans+=1ll*f[i][0]*(max(1ll*i,r[i-1])-max(1ll*i,r[i]-2));
		}*/
		for(int i=1;i<=n;i++){
			if(l[i]+1<i) ans+=f[l[i]+1][0];
			if(l[i]<i) ans+=f[l[i]][1];
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
CSP-S rp += inf
NOIP rp += inf
Never give up any problems as I have lost NOIP2025.
See ancestors on Halloween at /discuss/898803.
//froepen
//ferepen
//retrun
A pair is valid only if there is one point on the path can be moved.
awa
awawa
awawawa
awawawawa
awawawawawa
*/
