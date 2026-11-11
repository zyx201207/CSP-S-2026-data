#include<bits/stdc++.h>
using namespace std;using ll=long long;using ull=unsigned long long;

//maintain three pointers: left checkpoint, right p(sum)1, right p(sum)2

constexpr int N=2e6+9;
constexpr 
ll a[N],ps[N],n,d,ans;
int f[N],nxt[N],pa[N];
deque<int> dq; //range - max - qury mono deque
bool isbegin[N];
char type[N]; //seg-type: 1 for legal, 2 for illegal
int hw[N];
int hd[N]; //segment head
char it[N],ot[N];
int g[3]; //most previous: legal and illegal head, dual illegal h

inline ll sum(int l,int r){
	if(l>r) return 0;
	return ps[r]-ps[l-1];
}

inline bool con(int u,int v){
	if(u>v) swap(u,v);
	return a[v]-a[u]<=d;
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	dq.clear();
	isbegin[n+1]=1;
	for(int i=n;i>=1;i--){
		while(dq.size()&&!con(i,de.begin())) dq.pop_front();
		if(dq.empty()){ //a new begin
			f[i]=0;
			isbegin[i]=1;
			dq.push_back(i);
			continue;
		}
		f[i]=f[dq.front()]+1;
		nxt[i]=dq.front();
		while(dq.size()&&f[dq.back()]>=f[i]) dq.pop_back();
		dq.push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(isbegin[i]){
			int u=i;
			while(u){
				hw[u]=u;
				u=nxt[u];
			}
		}
		else{
			hw[i]=hw[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		if(!isbegin[i]){
			if(hw[i]==i){
				pa[i]=hw[i-1];
			}
			else{
				pa[i]=hw[i];
			}
		}
	}
	for(int i=1;i<=n;i++){ //check 2-route-replaces
		//check in
		int u=nxt[i],v=nxt[u];
		if(v){
			char flag=0;
			for(int j=i+1;j<v;j++){
				if(j==u) continue;
				if(con(i,j)&&con(j,v)){
					flag++;
					if(flag>1) break;
				}
			}
			it[i]=flag;
		}
		v=pa[i],u=pa[v];
		if(u){
			char flag=0;
			for(int j=u+1;j<i;j++){
				if(j==v) continue;
				if(con(u,j)&&con(j,i)){
					flag++;
					if(flag>1) break;
				}
			}
			ot[i]=flag;
		}
//		int u=nxt[i],v=nxt[u];
//		if(!v) continue;
//		char flag=0;
//		for(int j=i+1;j<v;j++){
//			if(j==u) continue;
//			if(con(i,j)&&con(j,v)){
//				flag++;
//				if(flag>1) break;
//			}
//		}
//		g[0]=min(g[0],g[u]);
//		g[1]=min(g[1],g[u]);
//		type[i]=flag;
//		if(type[i]==1) g[0]=i;
//		if(type[i]==2)
	}
	for(int i=n;i;i--){
		if()
	}
	for(int i=1,j,k;i<=n;i++){
		if(isbegin[i]) j=k=i; //the beginning of a connected segment
		while(!isbegin[j+1]&&!del[0]){
			j++;
			if(hd[j]>=i&&segtype[j]==0) del[0]=hd[j];
		}
		while(!isbegin[k+1]&&!del[1]){
			k++;
			if(hd[k]>=i&&segtype[k]==0) del[1]=hd[k];
		}
		
	}
//	for(int i=2;i<=n;i++){
//		if(a[i+1]-a[i-1]<=d) ps[i]++;
//	}
//	partial_sum(ps,ps+n+1,ps);
//	for(int i=1,j=1,k=1;i<=n;i++){
//		while(j<n&&sum(i+1,j-1)<1) j++;
//		while(k<n&&sum(i+1,k-1)<2) k++;
//		if(sum(i+1,j-1)==0) continue;
//		cout<<'#'<<' '<<i<<' '<<j<<' '<<k<<'\n';
//		if(sum(i+1,k-1)<2){
//			ans+=k-j+1; //k is doable
//		}
//		else{
//			ans+=k-j;
//		}
//	}
//	cout<<ans<<'\n';
//	ans=0;
//	for(int i=0;i<=n;i++) ps[i]=a[i]=0;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
