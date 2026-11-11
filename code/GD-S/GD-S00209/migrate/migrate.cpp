#include<bits/stdc++.h>
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;
int c,T,n,d,a[2000010],sum[2000010];
PII f[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=10){
			int ans=0;
			for(int i=1;i<=n;i++){
				int l=i,r=i;
				f[i]={0,1};
				sum[i]=1;sum[i-1]=0;
				for(int j=i+1;j<=n;j++){
					while(a[l]<a[j]-d) l++;
					r=max(r,l);
					while(f[r+1].fi==f[l].fi&&r+1<j) r++;
					f[j]={f[l].fi+1,sum[r]-sum[l-1]};
					sum[j]=sum[j-1]+f[j].se;
				}
				for(int j=i+1;j<=n;j++){
//					cout<<f[j].fi<<" "<<f[j].se<<" ";
					if(f[j].se==2){
						ans++;
					}
				}
//				cout<<endl;
			}
			cout<<ans<<'\n';
		}
		else if(c==11||c==12){
			int ans=0;
			int l=1,r=1;
			f[1]={0,1};
			sum[1]=1;sum[1-1]=0;
			for(int j=2;j<=n;j++){
				while(a[l]<a[j]-d) l++;
				r=max(r,l);
				while(f[r+1].fi==f[l].fi&&r+1<j) r++;
				f[j]={f[l].fi+1,sum[r]-sum[l-1]};
				sum[j]=sum[j-1]+f[j].se;
			}
			for(int j=2;j<=n;j++){
//					cout<<f[j].fi<<" "<<f[j].se<<" ";
				if(f[j].se==2){
					ans+=n-j+1;
				}
			}
			cout<<ans<<'\n';
		}
		else if(c==13||c==14){
			int idx=0;
			for(int i=1;i<=n;i++){
				if(a[n]-a[i]<=d){
					idx=i;break;
				}
			}
			int idx2=n+1;
			for(int i=n;i>=1;i--){
				if(a[i]-a[1]<=d){
					idx2=i;break;
				}
			}
			idx2=min(idx-1,idx2);
			int l=1;
			int ans=0;
			for(int i=idx;i<=n;i++){
				while(a[i]-a[l]>d) l++;
				if(i-l==2) ans+=l-1;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
