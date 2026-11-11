#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=2e6;
const ll inf=1e18;

ll n,d,m;
ll a[N+10],pos[N+10][2];
ll L[N+10],R[N+10];
ll f[N+10],g[N+10],cnt[N+10];
ll T,H,q[N+10];

inline bool cmp(int x){
	int l=x,r=x+1;
	return a[l]-a[l-1]<=d && a[r]-a[l-1]<=d && a[r+1]-a[l]<=d && a[r+1]-a[r]<=d && a[r+1]-a[l-1]>d;
}

inline void solve(){
	cin>>n>>d;
	
	bool flaggg=1;
	m=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flaggg=0;
			break;
		}
	}
	
	//flaggg=0;
	
	if(flaggg){
		d=d/(a[2]-a[1]);
		if(d<=1){
			cout<<0<<'\n';
		}
		else {
			cout<<max(0ll,n-(d*2-1))<<'\n';
		}
		return ;
	}
	
	else if(n<=3){
		cout<<0<<'\n';
		return ;
	}
	
	else if(n<=5000){
		ll ans=0;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[j]=cnt[j]=0;
				f[j]=inf;
			}
			
			f[i]=g[i]=1;
			T=H=1;
			q[T]=i;
			cnt[f[i]]+=g[i];
			
			for(int j=i+1;j<=n;j++){
				while(H<=T && abs(a[q[H]]-a[j])>d){
					cnt[f[q[H]]]-=g[q[H]];
					H++;
				}
				
				if(H>T) break;
				f[j]=f[q[H]]+1;
				g[j]=cnt[f[q[H]]];
				
				//cerr<<q[H]<<" ";
				
				while(H<=T && f[q[T]]>f[j]){
					cnt[f[q[T]]]-=g[q[T]];
					T--;
				}
				
				q[++T]=j;
				cnt[f[j]]+=g[j];
			}
			
			for(int j=i;j<=n;j++){
				//cerr<<f[j]<<" ";
				if(g[j]==2){
					ans++;
				}
			}
			
			//cerr<<endl;
		}
		
		cout<<ans<<'\n';
		
		return ;
	}
		
	for(int i=2;i<=n-2;i++){
		if(cmp(i)){
			m++;
			pos[m][0]=i;
			pos[m][1]=i+1;
		}
	}
	
	for(int i=1;i<=n;i++){
		L[i]=R[i]=i;
	}
	
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]<=d){
			L[i]=L[i-1];
		}
	}
	
	for(int i=n-1;i>=1;i--){
		if(a[i+1]-a[i]<=d){
			R[i]=R[i+1];
		}
	}
	
	ll ans=0;
	pos[m+1][1]=n;
	
	for(int i=1;i<=m;i++){
		ll l=max(L[pos[i][0]],pos[i-1][0]);
		ll r=min(R[pos[i][1]],pos[i+1][1]);
		ans+=((pos[i][0]-l)*(r-pos[i][1]));
	}
	
	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int _;
	cin>>_>>_;
	while(_--){
		solve();
	}
	
	return 0;
}
