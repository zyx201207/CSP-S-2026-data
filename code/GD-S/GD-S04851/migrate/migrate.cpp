#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,m,N,s,z,mn,ans,a[2000005],g[5005][5005],f[5005][5005];
struct node{int l,r,z;}A[2000005];
void dfs(int x,int y,int d){
	if(x==y){
		if(s<mn) mn=s,z=1;
		else if(s==mn) z++;
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]>m) break;
		s++,dfs(i,y,d),s--;
	}
}
void wk(){
	cin>>n>>m,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c==13||c==14||n==1){cout<<"0\n";return;}
	if(c<3){
		for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) mn=1e9,s=z=0,dfs(i,j,i),ans+=(z==2);
		cout<<ans<<"\n";return;
	}
	if(c==11||c==12){
		N=m/(a[2]-a[1]);
		if(N<2){cout<<"0\n";return;}
		for(int i=1;i+2*N-1<=n;i++) ans++;
		cout<<ans<<"\n";return;
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) g[i][j]=g[j][i]=-1;
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<n;i++){
		int j=i,k=0,z=0;
		while(j<n){
			int l=j+1,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[j]+m>=a[mid]) l=mid+1;
				else r=mid-1;
			}
			if(l==j+1) break;
			A[++k]={j+1,l-1,++z},j=l-1;
		}
		for(int o=1;o<=k;o++) for(int l=A[o].l;l<=A[o].r;l++) g[i][l]=g[l][i]=A[o].z;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		if(i!=j) f[i][j]=0;
		else f[i][j]=1;
	for(int i=1;i<n;i++) for(int j=1;j+i<=n;j++){
		if(g[j][j+i]<0) continue;
		int x=0,y=0;
		for(int k=j+1;k<j+i;k++){
			if(g[j][k]+g[k][j+i]>g[j][j+i]) continue;
			x=max(x,g[j][k]),y+=f[j][k]*f[k][j+i];
		}
		if(x) f[j][j+i]=y/x;
		if(!f[j][j+i]) f[j][j+i]=1;
		if(f[j][j+i]==2) ans++;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>T;
	while(T--) wk();
	return 0;
}
