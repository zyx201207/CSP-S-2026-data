#include <bits/stdc++.h>
#define ll long long
using namespace std;
int const MN=2000501;
int c,t;
int n;
ll d,a[MN];
struct L{int l,r,p1,p2;}b[MN],b2[MN];
bool bo[MN];
void solve(){
	int cnt=0;ll ans=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		bo[i]=0;
	}for(int l=n;l>=1;l--){
		for(int r=l+3;r<=n;r++){
			if(bo[r])continue;
			int p1=upper_bound(a+l,a+r+1,d+a[l])-a-1;
			int p2=lower_bound(a+l,a+r+1,a[r]-d)-a;
			if(p1-p2==1){
				b2[++cnt]={l,r,p1,p2};
				bo[r]=1;
				break;
			}
		}
	}b[cnt+1].r=n+1;
	for(int i=1;i<=cnt;i++){
		b[i]=b2[cnt-i+1];
	}for(int i=1;i<=cnt;i++){
		int t1=1,t2=1;
		for(int l=b[i].l;l>b[i-1].l+1;l--){
			if(a[l]-a[l-1]>d)break;t1++;
		}for(int r=b[i].r;r<b[i+1].r-1;r++){
			if(a[r+1]-a[r]>d)break;t2++;
		}ans+=1ll*t1*t2;
	}printf("%lld\n",ans);
}int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)solve();
	return 0;
}/*
&&(r==n||a[r+1]-a[p1]>d)
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
