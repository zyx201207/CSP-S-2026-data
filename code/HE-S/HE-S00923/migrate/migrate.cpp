#include<bits/stdc++.h>
using namespace std;
long long c,n,d,t,a[2000010];
int mm[2000010];
pair<int,int> b[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(mm,1,sizeof mm);
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		int cc=0;
		for(int i=1;i<=n-3;i++){
			if(a[i]+d>=a[i+2] && a[i+1]+d>=a[i+3] && a[i]+d<a[i+3]) b[++cc]={i,i+3};
		}
		for(int i=1;i<=n-2;i++) if(a[i]+d>=a[i+2]) mm[i]=0,mm[i+1]=0,mm[i+2]=0;
		for(int i=1;i<=cc;i++){
			int l=b[i].first,r=b[i].second,xl=1,xr=1;
			while(l>1 && mm[l-1] && a[l-1]+d>=a[l]) l--,xl++;
			while(r<n && mm[r+1] && a[r]+d>=a[r+1]) r++,xr++;
			ans+=1ll*(xl*xr);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
