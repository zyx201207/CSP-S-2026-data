#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define req(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		vector<int> a(n+1),nxt(n+1),run(n+1);
		rep(i,1,n) cin>>a[i];
		rep(i,1,n){
			int l=i+1,r=n,res=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[mid]-a[i]<=d) res=mid,l=mid+1;
				else r=mid-1;
			}
			nxt[i]=res;
			// cerr<<"nxt "<<i<<" = "<<j-1<<'\n';
		}
		rep(i,1,n){
			int j=i;
			while(j<n&&nxt[j]==j+1) j=nxt[j];
			rep(k,i,j) run[k]=j-k+1;
			// cerr<<i<<" to "<<j<<" is run\n";
			i=j;
		}
		int ans=0;
		vector<int> cache(n+1,-1);
		req(i,n,1){
			int p=i,cnt=0;
			vector<int> allp;
			while(p<n){
				//clog<<T<<" "<<i<<" "<<p<<endl;
				if(cache[p]!=-1){
					cnt+=cache[p];
					break;
				}
				else cache[p]=0;
				cache[p]-=cnt;
				allp.push_back(p);
				int np=nxt[p];
				if(np==p+1){
					p=np;
					continue;
				}
				if(np==p) break;
				int nnp=nxt[np],npnp=nxt[np-1];
				bool cond=true;
				if(np-p>2){
					int nppnp=nxt[np-2];
					if(nppnp==npnp) cond=false;
					np=max(np,nppnp);
				}
				if(!cond) break;
				if(cond&&np+1<=npnp){
					int last=npnp;
					if(npnp-np>=2&&nxt[npnp-1]==nxt[npnp]) cond=false;
					if(nnp==npnp&&cond){
						last+=run[last]-1;
						//while(last<n&&nxt[last]==last+1) last=nxt[last];
					}
					cnt+=last-np;
					//cerr<<"start "<<i<<", "<<np+1<<"~"<<npnp<<" good; last "<<last<<'\n';
					// break;
					if(c==11||c==12)break;
					p=np+1;
					//break;
					continue;
				}
				p=np;
			}
			for(auto p:allp) cache[p]+=cnt;
			ans+=cnt;
		}
		cout<<ans<<'\n';
		//exit(0);
	}
	return 0;
}
