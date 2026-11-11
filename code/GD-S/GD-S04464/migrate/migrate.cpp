#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;
int n,d,c,t,a[N],p,minx;
void land(int l,int r,int cnt,int maxs){
	if(cnt==minx){
		if(r>=maxs) p++;
		return;
	}
	while(a[r]-a[l]<=d) land(r,r+(r-l),cnt+1,maxs),r++;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(a[j]-a[i]<=d) continue;
				p=0,minx=0;
				int ir=i+1,il=i;
				while(ir<=j){
					if(a[ir]-a[il]<=d) ir++;
					else minx++,il=ir,ir++;
				}
				land(i,ir,1,j);
				if(p==1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
