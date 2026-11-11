#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
typedef unsigned long long ull;
const int N=3e3+10;
ll T,c,n,m,d,q,k,ar[N],dis[N],vis[N],ans[N],mis[N],tong[N];
vector<ll> vc[N];
void fd(ll x,ll bj){
	for(auto to:vc[x]){
        if(dis[to]>dis[x]+1){
        	dis[to]=dis[x]+1;
    		fd(to,bj);
		}
		
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		f(i,1,n){
			vc[i].clear();
		}
		f(i,1,n)cin>>ar[i];
		f(i,1,n){
			f(j,i+1,n){
				if(abs(ar[j]-ar[i])<=k){
					vc[i].push_back(j);
				}
			}
		}
		ll cnt=0;
		f(i,1,n){
			memset(dis,0x3f,sizeof(dis));
			dis[i]=0;
	    	fd(i,1);
	    	f(j,1,n)tong[j]=0;
	    	f(j,i,n){
//	    		cout<<dis[j]<<" ";
		    	for(auto to:vc[j]){
		    		if(dis[to]==dis[j]+1){
		    			tong[to]++;
//		    			cout<<tong[to]<<" ";
		    		}
		    	}
	    	}
	    	f(j,1,n)if(tong[j]==2)cnt++;
//	    	cout<<endl;
		}
		
		cout<<cnt<<endl;
	}
	return 0;
}
