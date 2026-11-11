#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T;
int n,d,lq,rq,ans,p[N],L[N],R[N];
int lres[N],rres[N];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>c>>T;
	while(T--) {
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>p[i];
		lq=1;
		for(int i=1;i<=n;i++) {
			while(p[i]-p[lq]>d) lq++;
			L[i]=lq;
		}
		rq=n;
		for(int i=n;i>=1;i--) {
			while(p[rq]-p[i]>d) rq--;
			R[i]=rq;
		}
		for(int i=1;i<=n;i++) {
			int l=L[i],r=L[i+1]-1;
			lres[i]=1;
			if(l>r) continue;
			lres[i]=lres[l]+r-l+1;
		}
		for(int i=n;i>=1;i--) {
			int r=R[i],l=R[i-1]+1;
			rres[i]=1;
			if(l>r) continue;
			rres[i]=rres[r]+r-l+1;
		}
		for(int i=2;i<n-1;i++) {
			int j=i+1,x=i-1,y=i+2;
			int lL=L[j],lR=min(L[y]-1,x),rL=max(R[x]+1,y),rR=R[i];
			if(lL>lR||rL>rR) continue;
			int lsum=lR-lL+1,rsum=rR-rL+1;
			if(L[i]==L[j]) lsum+=lres[lL]-1;
			if(R[i]==R[j]) rsum+=rres[rR]-1;
			ans=(ans+(lsum)*(rsum));
		}
		cout<<ans<<"\n";
	}
}
