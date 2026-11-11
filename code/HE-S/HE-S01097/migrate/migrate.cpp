#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,D,a[N],nxt[N],A[N],val[N][3][3];
int solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		nxt[i]=max(nxt[i-1],i);
		while(nxt[i]<n && a[nxt[i]+1]<=a[i]+D) nxt[i]++;
	}
	for(int r=n-1;r>=1;r--){
		for(int l=r-1;l<=r;l++){
			for(int p1=0;p1<=2;p1++){
				int nl=r+1,nr=nxt[r],np1=0,np2=0;
				if(r-l+1==1){
					if(p1) np1=nr-nl+1,np2=0;
					else{
						np1=0;
						np2=nr-nl+1;
					}
				}else{
					int x=min(nr+1,max(nl,nxt[r-2]+1));
					int y=min(nr+1,max(nl,nxt[r-1]+1));
					if(p1>=2){
						np1=nr-y+1;
						np2=y-x;
					}else if(p1){
						np1=nr-y+1;
						np2=0;
					}else{
						np2=nr-y+1;
						np1=0;
					}
				}
				if(!np1 && !np2) continue;
				val[r][r-l+1][p1]=val[nr][min(2ll,nr-nl+1)][min(np1,2ll)]+np2;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		ans+=val[i][1][1];
	}
	for(int i=1;i<=n;i++) for(int j=0;j<=2;j++) for(int k=0;k<=2;k++) val[i][j][k]=0;
	return ans;
}
signed main(){
//	system("fc migrate.out migrate6.ans"); return 0;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin>>T>>T;
	while(T--){
		int N,lst=1,ans=0;
		cin>>N>>D;
		for(int i=1;i<=N;i++) cin>>A[i];
		for(int i=1;i<=N;i++){
			if(i==N || A[i]+D<A[i+1]){
				for(int j=lst;j<=i;j++) a[j-lst+1]=A[j];
				n=i-lst+1;
				ans=(ans+solve());
				lst=i+1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
