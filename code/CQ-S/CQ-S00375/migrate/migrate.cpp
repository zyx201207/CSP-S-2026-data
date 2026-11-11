#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000010],f[2000010],ans,b[2000010],cnt,pre[2000010],suf[2000010],l[2000010],r[2000010];
void solve(){
	for(int i=2;i+1<cnt;i++){
		int l=i,r=i+1;
		while(l-1>0&&b[i+2]-b[l]<=d)l--;
		while(r+1<=cnt&&b[r]-b[i-1]<=d)r++;
		if(l==i||r==i+1||b[i+1]-b[i]>d||b[i+1]-b[l]>d||b[r]-b[i]>d||b[i+2]-b[l]<=d||b[r]-b[i-1]<=d)continue;
		pre[l]=1,suf[r]=1;
	}
	for(int i=1;i<=cnt;i++){
		if(pre[i]==1)pre[i]=0;
		else pre[i]=pre[i-1]+1;
	}
	for(int i=cnt;i>=1;i--){
		if(suf[i]==1)suf[i]=0;
		else suf[i]=suf[i+1]+1;
	}
	for(int i=2;i+1<cnt;i++){
		int l=i,r=i+1;
		while(l-1>0&&b[i+2]-b[l]<=d)l--;
		while(r+1<=cnt&&b[r]-b[i-1]<=d)r++;
		if(l==i||r==i+1||b[i+1]-b[i]>d||b[i+1]-b[l]>d||b[r]-b[i]>d||b[i+2]-b[l]<=d||b[r]-b[i-1]<=d)continue;
		ans+=(pre[l-1]+1)*(suf[r+1]+1);
	}
	for(int i=1;i<=cnt;i++)pre[i]=suf[i]=0;
	cnt=0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			b[++cnt]=a[i];
			if(a[i+1]-a[i]>d)solve();
		}
		if(cnt!=0)solve();
		cout<<ans<<"\n";
	} 
	return 0;
}
/*

*/
