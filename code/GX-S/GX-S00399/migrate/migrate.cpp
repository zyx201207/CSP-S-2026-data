#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const long long inf=1e18;
int c,t;
long long n,d,x[N],z[N],ans,l[N],r[N],ly,yl[N],f[N],g[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=5000){
			ans=0;
			for(int i=1;i<=n;i++)cin>>x[i];
			ly=1;
			for(int i=1;i<=n;i++){
				while(x[i]-x[ly]>d&&ly<i)ly++;
				l[i]=ly;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++)f[j]=inf,g[j]=inf;
				g[i]=1;
				f[i]=0;
				for(int j=i+1;j<=n;j++){
					if(l[j]==j)break;
					int lp=max(l[j],(long long)i);
					for(int k=1;k<=3&&lp+k<=j;k++){
						if(f[j]>f[lp+k-1]+1){
							f[j]=f[lp+k-1]+1;
							g[j]=g[lp+k-1];
						}else if(f[j]==f[lp+k-1]+1){
							g[j]+=g[lp+k-1];
						}
					}
					if(g[j]==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}else{
			ans=0;
			for(int i=1;i<=n;i++)cin>>x[i],z[i]=0;
			ly=1;
			for(int i=1;i<=n;i++){
				while(x[i]-x[ly]>d&&ly<i)ly++;
				l[i]=ly;
			}
			ly=n;
			for(int i=n;i>=1;i--){
				while(x[ly]-x[i]>d&&ly>i)ly--;
				r[i]=ly;
			}
			ly=0;
			for(int i=1;i<=n;i++)yl[i]=1;
			for(int i=1;i<=n;i++){
				if(i!=1&&l[i]==i)ly=0;
				ly+=yl[i];
				if(r[i]<=i+1)continue;
				if(r[r[i]-1]==r[r[i]-2])continue;
				if(l[r[i]]!=l[r[i]-1]){
					if(r[r[i]]!=r[r[i]-1])yl[r[r[i]-1]+1]+=min(ly,i-l[r[i]]+1);
					z[r[i]-1]+=min(ly,i-l[r[i]]+1);
					ly-=min(ly,i-l[r[i]]+1);
				}else{
					if(r[r[i]]!=r[r[i]-1])yl[r[r[i]-1]+1]+=ly;
					z[r[i]-1]+=ly;
					ly=0;
				}
			}
			ly=0;
			for(int i=1;i<=n;i++)yl[i]=1;
			for(int i=n;i>=1;i--){
				if(i!=n&&r[i]==i)ly=0;
				ly+=yl[i];
				if(l[i]>=i-1)continue;
				if(l[l[i]+1]==l[l[i]+2])continue;
				if(r[l[i]]!=r[l[i]+1]){
					if(l[l[i]]!=l[l[i]+1])yl[l[l[i]+1]-1]+=min(ly,r[l[i]]-i+1);
					ans+=z[l[i]]*min(ly,r[l[i]]-i+1);
					ly-=min(ly,r[l[i]]-i+1);
				}else{
					if(l[l[i]]!=l[l[i]+1])yl[l[l[i]+1]-1]+=ly;
					ans+=z[l[i]]*ly;
					ly=0;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
