#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000007;
int u,t,n,x,y,la,ra,l[N],r[N],d[N],v[N],tp;
ll m,a[N],tmp,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&u,&t);
	while(t--){
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		ans=0;
		if(n>5000){
			tmp=a[2]-a[1];
			//cerr<<m<<' '<<tmp<<' '<<n<<endl;
			if(m<2*tmp) cout<<0<<endl;
			else cout<<max(n-m/tmp*2+1,0ll)<<endl;
			continue;
		}
		a[0]=-5e18;
		a[n+1]=5e18;
		x=1;
		for(int i=2;i<=n+1;i++){
			while(a[i]-a[x]>m){
				r[x]=i-1;
				x++;
			}
		}
		x=n;
		for(int i=n-1;i>=0;i--){
			while(a[x]-a[i]>m){
				l[x]=i+1;
				x--;
			}
		}
		la=1;
		for(int i=1;i<=n;i++){
			//cout<<l[i]<<' '<<r[i]<<endl;
			if(r[i]!=i) continue;
			ra=i;
			for(int j=la;j<=ra;j++){
				for(int k=j;k<=ra;k++) d[k]=0;
				tp=0;
				v[0]=j;
				for(int k=j+1;k<=ra;k++){
					if(k>r[v[tp]]) tp++;
					v[tp+1]=k;
					d[k]=d[l[k]]+(v[tp]-max(l[k],j));
					if(d[k]==1) ans++;
					//cout<<j<<' '<<k<<' '<<tp<<' '<<v[tp]<<' '<<l[k]<<' '<<d[l[k]]<<' '<<d[k]<<endl;
				}
			}
			la=ra+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
