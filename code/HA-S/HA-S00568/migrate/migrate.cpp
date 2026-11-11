#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define pii pair<int,int>

const int N=2e6+10;

int dlh,T,n,p[N];
ll a[N],ans,d,f[N],g[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>dlh>>T;
	while(T--){
		cin>>n>>d;
		if(n<=3){
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<0<<"\n";
			continue;
		}
		ans=0;
		int flag=1;
		ll delta=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2){
				delta=a[i]-a[i-1];	
			}else if(i>2){
				if(a[i]-a[i-1]!=delta)flag=0;
			}
			int l=1,r=i,mid;
			while(l<r){
				mid=(l+r)>>1;
				if(a[i]-a[mid]<=d)r=mid;
				else l=mid+1;
			} 
			p[i]=l;
		}
		if(flag){ 
			ll c=d/delta;
			if(c<2ll)cout<<0<<"\n";
			else cout<<max(0ll,(ll)n-c*2+1)<<"\n";
			continue;
		}else{
			int L;
			for(int i=1;i<=n;i++){
				f[i]=1,g[i]=0;
				for(int j=i+1;j<=n;j++){
					L=max(i,p[j]);
					if(L==j)f[j]=0,g[j]=1e9;
					else{
						if(L==j-1)f[j]=f[L];
						else if(L==j-2){
							if(g[L]==g[L+1])f[j]=f[L]+f[L+1];
							else f[j]=f[L];
						}else{
							if(g[L]==g[L+1]&&g[L]==g[L+2])f[j]=f[L]+f[L+1]+f[L+2];
							else if(g[L]==g[L+1])f[j]=f[L]+f[L+1];
							else f[j]=f[L];
						}
						if(f[j]>2)f[j]=3;
						if(f[j]==2){
							ans++;
						}
						g[j]=g[L]+1;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}

	return 0;
}


