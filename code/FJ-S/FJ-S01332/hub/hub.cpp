#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e6+5;
int c,t,n,k,x[N],y[N],cnt[N],ct[N],bl[N],siz[2],num,ans;
vector<int> s[N],p,q;
inline void f(int x,int fa,int pd){
	siz[pd]++,bl[x]=pd;
	for(int y:s[x]){
		if(y!=fa) f(y,x,pd);
	}
	return;
}
inline int solve(int x,int y){
	int sum=n,ij=0;
	p.clear();
	siz[0]=siz[1]=0;
	f(x,y,0),f(y,x,1);
	for(int i=1;i<=n;i++){
		cnt[i]=ct[i];
		if(i==x || i==y) cnt[i]--;
		if(cnt[i]==1) cnt[i]=0,p.pb(i);
	}
	while(sum>k && !p.empty()){
		q=p,ij++;
		p.clear();
		for(int x:q){
			if(siz[bl[x]]==1) continue;
			siz[bl[x]]--,sum--;
			if(sum<=k) return ij;
			for(int y:s[x]){
				if(bl[x]!=bl[y]) continue;
				else if(cnt[y]) cnt[y]--;
				if(cnt[y]==1){
					cnt[y]=0,p.pb(y);
				}
			}
		}
	}
	return n;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<=n;i++) s[i].clear();
		for(int i=1;i<n;i++){
			cin >> x[i] >> y[i];
			s[x[i]].pb(y[i]),s[y[i]].pb(x[i]);
		}
		if(n==k){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			ct[i]=s[i].size();
		}
		ans=n;
		for(int i=1;i<n;i++){
			num=solve(x[i],y[i]);
			ans=min(ans,num);
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
