#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,x[N],d;
int nxt[N],lst[N],cnt[N][2];
int pre[N][4],f[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i],lst[i]=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;nxt[i]=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(x[mid]-x[i]<=d)nxt[i]=mid,l=mid+1;
			else r=mid-1;
		}
//		if(!lst[nxt[i]])lst[nxt[i]]=i;
//		cout<<nxt[i]<<" ";
	}
	int now=1;
	for(int i=1;i<=n;i++){
		while(nxt[now]<i)++now;
		lst[i]=now;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		f[i]=1;pre[i][1]=1,pre[i][2]=pre[i][3]=0;
		for(int j=i;nxt[j]!=j;j=nxt[j]){
			for(int k=j+1;k<=nxt[j];k++){
				int x=pre[j][1]-(lst[k]-1<i?0:pre[lst[k]-1][1]);
				int y=pre[j][2]-(lst[k]-1<i?0:pre[lst[k]-1][2]);
				int z=pre[j][3]-(lst[k]-1<i?0:pre[lst[k]-1][3]);
				if(z||x+2*y>2)f[k]=3;
				else f[k]=x+2*y;
//				f[k]=pre[j]-(lst[k]-1<i?0:pre[lst[k]-1]);
//				pre[k]=pre[k-1]+f[k];
				pre[k][1]=pre[k-1][1],pre[k][2]=pre[k-1][2],pre[k][3]=pre[k-1][3];
				pre[k][f[k]]++;
//				cerr<<pre[k][1]<<"\n";
				ans+=(f[k]==2);
//				cerr<<k<<":"<<f[k]<<"\n";
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;cin>>C>>T;
	while(T--)solve();
	return 0;
}
/*

6 4
-3 0 1 2 3 4
*/
