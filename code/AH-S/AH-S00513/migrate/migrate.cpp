#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2000010,N_=5010;
int c,T,n,d,x[N],L[N],R[N],f[N],g[N],sf[N],sg[N],dis[N_][N_];
namespace Sub1{
	void solve(){
		if(x[3]-x[1]<=d&&x[4]-x[1]>d) cout<<n-3<<'\n';
		else cout<<"0\n";
	}
}
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>c>>T;while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i],sf[i]=f[i]=0;
		if(11<=c&&c<=12) {Sub1::solve();continue;}
		deque<int> q;
		L[0]=1;// check it
		for(int i=1;i<=n;i++){
			while(!q.empty()&&x[i]-x[q.front()]>d) q.pop_front();
			L[i]=(q.empty()?i:q.front());
			q.push_back(i);
		}q.clear();
		for(int i=n;i>=1;i--){
			while(!q.empty()&&x[q.front()]-x[i]>d) q.pop_front();
			R[i]=(q.empty()?i:q.front());
			q.push_back(i);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int r=R[i],l=R[i]-1;
			for(int j=r+1;r<=n;r++){
				if(x[j]-x[l]<=d&&x[j]-x[l-1]>d)
			}
		}
	}
}
