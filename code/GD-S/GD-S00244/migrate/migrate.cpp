#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
__int128 dd;
int C,T,n,d,a[N],nxt[N],f[N][2];
void solve(){
	int ans=0;
	sort(a+1,a+n+1);
	int p=n;
	for(int i=n;i>=1;i--){
		while(a[p]-a[i]>d) p--;
		nxt[i]=p;
	} 
	for(int i=n;i>=1;i--){
		f[i][1]=f[i][0]=0;
		int j=nxt[i],k=nxt[j];
		if(i==j||j==k) continue;
		int s=j-(lower_bound(a+i,a+k+1,a[k]-d)-a);
		int ll=max(j+1,upper_bound(a,a+k+1,d+a[j-2])-a);
		if(j-2==i) ll=j+1;
		int rr=min(upper_bound(a,a+k+1,d+a[j-1])-a,k+1);
		f[i][0]+=max(rr-ll,0ll);
		f[i][1]+=max(k-rr+1,0ll);
		if(s==0){
			f[i][0]+=f[j][0];
			f[i][1]+=f[j][1];
		}else if(s==1) f[i][0]+=f[j][1];
		ans+=f[i][0];
	}
	
//	for(int i=1;i<=n;i++)
//		cerr<<f[i][0]<<' '<<f[i][1]<<'\n';
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		dd=d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} solve();
	}
	return 0;
}
/*
1 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
