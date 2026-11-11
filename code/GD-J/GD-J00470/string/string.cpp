#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+21;
int n;
struct edge{
	char c;
	int l,r;
}a[N];
int ll[N],rr[N];
bool cmp(edge x,edge y){
	if(x.c==y.c)return x.l<y.l;
	return x.c<y.c;
}
int solve(int l1,int r1,int l2,int r2){
	if(l1>l2)swap(l1,l2),swap(r1,r2);
	if(r1<l2)return 0;
	if(r2<=r1)return r2-l2+1;
	return r1-l2+1;
}
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int L=1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x>>a[i].c;
		a[i].l=L;
		a[i].r=L+x-1;
		L+=x;
	}
	L--;
	sort(a+1,a+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i].c==a[i-1].c){
			ll[++cnt]=a[i].l;
			rr[cnt]=a[i].r;
		}else{
			if(i!=1){
				for(int j=1;j<=cnt;j++){
					int xl=L-rr[j]+1,xr=L-ll[j]+1;
					int kl=lower_bound(rr+1,rr+cnt+1,xl)-rr;
					int kr=upper_bound(ll+1,ll+cnt+1,xr)-ll-1;
					if(kl<j)kl=j;
					for(int k=kl;k<=kr;k++){
						int sum=solve(xl,xr,ll[k],rr[k]);
						if(k==j)sum=(sum+1)/2;
						if(sum==0)break;
						ans+=sum;
					}
				}
			}
			cnt=1;
			ll[cnt]=a[i].l;
			rr[cnt]=a[i].r;
		}
	}
	for(int j=1;j<=cnt;j++){
		int xl=L-rr[j]+1,xr=L-ll[j]+1;
		int kl=lower_bound(rr+1,rr+cnt+1,xl)-rr;
		int kr=upper_bound(ll+1,ll+cnt+1,xr)-ll-1;
		if(kl<j)kl=j;
		for(int k=kl;k<=kr;k++){
			int sum=solve(xl,xr,ll[k],rr[k]);
			if(k==j)sum=(sum+1)/2;
			if(sum==0)break;
			ans+=sum;
		}
	}
	cout<<(L+1)/2-ans;
}
