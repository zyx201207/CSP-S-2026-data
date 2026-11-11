#include<bits/stdc++.h>
#define int long long
using namespace std;
int cc,t,n,d,a[1000005],cnt,cnt2,ans;
struct qj{
	int l,r;
}b[1000005],c[1000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>cc>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		b[1].l=1;
		cnt=1;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]>d){
				b[cnt].r=i-1;
				cnt++;
				b[cnt].l=i;
			}
		}
		b[cnt].r=n;
		cnt2=0;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-2]<=d&&i-2>=c[cnt2].r){
				c[++cnt2].l=i-2,c[cnt2].r=i;
			}
		}
		int now=1;
		ans=0;
		for(int i=1;i<=cnt;i++){
			int ll=b[i].l,rr=b[i].r;
			while(c[now].r<=b[i].r&&now<=cnt2){
				int jsl=max((long long)1,c[now].l-max(ll,c[now-1].r+1)+1);
				int jsr=max((long long)1,min(rr,c[now+1].l-1)-c[now].r+1);
				ans+=jsl*jsr;
				now++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

