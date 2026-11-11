#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e6+5;
int c,T,n,d,x[N],l[N],r[N],p1[N],q1[N],p2[N],q2[N],u[N],v[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;while(T--){
		cin>>n>>d;int L=1,R=1,ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12){
			d/=(x[2]-x[1]);
			for(int i=1;i<=n;i++)
				if(i+d<=n) ans+=min(n,i+2*d-1)-(i+d)+1;
			cout<<ans<<"\n";continue;
		}
		for(int i=1;i<=n;i++){
			while(L<=n&&x[i]-x[L]>d) L++;l[i]=L;
			while(R<=n&&x[R]-x[i]<=d) R++;r[i]=R-1;
		}
		for(int i=1;i<=n;i++){
			if(l[i]==l[i-1]) q1[i]++;else p1[i]=q1[i]=l[i];
			if(r[i]==r[i-1]) q2[i]++;else p2[i]=q2[i]=r[i];
		}
		for(int i=1;i<=n;i++)
			u[i]=p1[r[p1[r[i]-1]]],v[i]=q1[r[q1[r[i]-1]]];
		for(int i=1;i<=n;i++)
			ans+=(i-p2[l[i]]+1)*(v[i]-u[i]+1)+(i+1-p2[l[i+1]]+1)*(v[i+1]-u[i+1]+1)-max((int)0,(i-p2[l[i+1]]+1)*(u[i+1]-v[i]+1));
		cout<<ans<<"\n";
	}
	return 0;
}

