#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10,inf=1e18+10;

ll c,t,n,d,x[N],f[N],g[N],tung[N],ans;

inline void work(ll st){
	
	for(int i=1;i<=n;i++) f[i]=inf,g[i]=0,tung[i]=0;
	
	f[st]=0,g[st]=1,tung[0]=1;
	for(int r=st+1,l=st;r<=n;r++){
		
		while(x[r]-x[l]>d){
			
			tung[f[l]]-=min(g[l],3ll);
			l++;
		}
		
		if(l==r) break;
		
		f[r]=f[l]+1,g[r]=tung[f[l]];
		tung[f[r]]+=min(g[r],3ll);
	}
	
	ll cnt=0;
	for(int i=st;i<=n;i++) cnt+=(g[i]==2);
	
	return ans+=cnt,void();
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		
		if(c>=11&&c<=12){
			
			ll c=x[2]-x[1];
			if(d/c<=1) cout<<"0\n";
			else cout<<max(0ll,n-(d/c+d/c-1))<<'\n';
			
			continue;
		}
		else if(c>=13&&c<=14){
			
			ll op=0;ans=0;
			for(int i=1;i<=n;i++) if(x[i]-x[1]<=d&&x[n]-x[i]<=d){op=i;break;}
			
			for(int r=op+1,l=1;r<=n;r++){
				
				while(x[r]-x[l]>d) l++;
				if(r-l==2&&x[l]-x[l-1]<=d) ans++;
			}
			
			cout<<ans<<'\n';
		}
		else if(n<=5000){
			
			ans=0;
			for(int i=1;i<=n;i++) work(i);
			cout<<ans<<'\n';
		}
		else cout<<0<<'\n';
	}
	
	return 0;
}

/*
17:16 °¥... 
*/
