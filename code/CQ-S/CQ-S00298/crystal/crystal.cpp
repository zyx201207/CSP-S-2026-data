#include<bits/stdc++.h>
#define LL long long int 
using namespace std;
const int N=5e5+10;
int n,ans;
LL m;
int nxt[N];
LL a[N],pre[N];
LL calc(int l,int r,LL x){
	int len=r-l+1;
	return len*x-(pre[r]-pre[l-1]);
}
int find(int l,int r,LL x){
	int ed=r;
	while(l<r){
		int mid=l+r>>1;
		if(calc(mid,ed,x)<=m) r=mid;
		else l=mid+1;
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	nxt[n]=n+1;
	for(int i=n-1;i>=1;i--){
		if(a[i]==a[i+1]) nxt[i]=nxt[i+1];
		else nxt[i]=i+1;
	}
	for(int i=1;i<=n;i++){
		int l=find(1,i,a[i]),r=nxt[i]-1;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
