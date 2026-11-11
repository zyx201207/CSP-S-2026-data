#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+22;
int n,d,a[N],cnt,sum,mi;
void check(int x,int tot,int y){
	if(x==y){
		if(tot<mi) mi=tot,sum=0;
		if(tot==mi) sum++;
		return ;
	}
	if(tot>mi) return ;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]>d) break;
		check(i,tot+1,y);
	}
}
void solve(){
	scanf("%lld%lld",&n,&d);
	cnt=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sum=0;
			mi=1e9;
			check(i,0,j);
			if(sum==2){
//				cout<<i<<' '<<j<<endl;
				cnt++;
			}
		}
	}
	printf("%lld\n",cnt);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%lld%lld",&c,&T);
	if(c==11 || c==12){
		while(T--){
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			int awa=d/(a[2]-a[1]);
			if(awa<=1) printf("0\n");
			else printf("%lld\n",max(0ll,n-(2*awa-1)));
		}
	}else{
		while(T--){
			solve();
		}
	}
}
