#include<bits/stdc++.h>
#define ll long long
using namespace std;
int tid,t,n;
ll m,a[2000005],cntl[2000005],cntr[2000005],ans;
struct node{
	int l,r;
}ncl[2000005],ncr[2000005];
template<typename T>
void read(T &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(f==-1) x=-x;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(tid),read(t);
	while(t--){
		read(n),read(m);
		memset(cntl,0,(n+1)*sizeof(ll));
		memset(cntr,0,(n+1)*sizeof(ll));
		ans=0;
		for(int i=1;i<=n;i++){
			read(a[i]);
		}
		a[0]=-4e18,a[n+1]=4e18;
		for(int i=1,nl=1,nr=1;i<=n;i++){
			nl=max(nl,i+1);
			while(nl<=n&&a[nl]-a[i-1]<=m) nl++;
			while(nr<=n&&a[nr]-a[i]<=m) nr++;
			ncr[i]={nl,nr-1};
		}
		for(int i=n,nl=n,nr=n;i>=1;i--){
			nr=min(nr,i-1);
			while(nr>=1&&a[i+1]-a[nr]<=m) nr--;
			while(nl>=1&&a[i]-a[nl]<=m) nl--;
			ncl[i]={nl+1,nr};
		}
		for(int i=1;i<=n;i++){
			if(ncl[i].l<=ncl[i].r){
				cntl[i]=ncl[i].r-ncl[i].l+1+cntl[ncl[i].l];
			}
		}
		for(int i=n;i>=1;i--){
			if(ncr[i].l<=ncr[i].r){
				cntr[i]=ncr[i].r-ncr[i].l+1+cntr[ncr[i].r];
			}
		}
		for(int i=1;i<=n;i++){
			cntl[i]++,cntr[i]++;
		}
		for(int i=1;i<=n;i++){
			int x2=ncl[i].l,x3=ncl[i].l+1,x1=ncl[x3].l;
			if(x1>=x2||x2>=x3||x3>=i||ncr[x1].r!=x3) continue;
			if(ncr[x3].r==i){
				int xxl=ncl[x3].l+1,xxr=min(ncl[x3].r,x2-1);
				if(ncl[x2].l==x1) ans+=cntr[i]*(cntl[x1]+(xxl<=xxr? xxr-xxl+1:0));
				else ans+=cntr[i]*(xxl-1<=xxr? xxr-xxl+2:0);
			}
			else{
				int xxl=ncl[x3].l+1,xxr=min(ncl[x3].r,x2-1);
				if(ncl[x2].l==x1) ans+=cntl[x1]+(xxl<=xxr? xxr-xxl+1:0);
				else ans+=(xxl-1<=xxr? xxr-xxl+2:0);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
