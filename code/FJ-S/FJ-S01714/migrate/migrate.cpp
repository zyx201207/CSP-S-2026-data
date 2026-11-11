#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000100
const int inf=1e9;
int n,d,T,f[N],a[N],b[N],ans,c;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int i,j,x,y;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			d=d/(a[2]-a[1]);
			ans=n-2*d+1;
			if(d<=1)cout<<0<<"\n";
			else cout<<max(ans,0ll)<<"\n";
			continue;
		}
		for(i=1;i<=n;i++){
			for(j=i;j<=n;j++)f[i]=0,b[i]=0;
			f[i]=0;
			for(j=i+1;j<=n;j++){
				int p=0;
				if(a[j]-a[j-1]>d)break;
				x=a[j]-d;
				y=lower_bound(a+1,a+j,x)-a;
				y=max(y,i);
				f[j]=f[y]+1;
				if(y+1<j&&f[y]==f[y+1])p++;
				if(y+2<j&&f[y]==f[y+2])p++;
				b[j]=b[y];
				if(p>0)b[j]=max(b[j],p+b[y+1]);
				if(b[j]==1)ans++;
//				cout<<i<<" "<<j<<" "<<b[j]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} /*
0 1
6 2
-4 -3 -2 -1 3 6
*/
