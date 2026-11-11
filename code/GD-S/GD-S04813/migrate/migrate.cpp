#include <bits/stdc++.h>
using namespace std;

//#undef DEBUG
using i64 = long long;
#ifdef DEBUG
void dbg(){cerr<<endl;}
template<typename A,typename...B>void dbg(A a,B...b){cerr<<a<<" ",dbg(b...);}
#define debug(x...) cerr<<"["<<#x<<"]: ", dbg(x)
#else
#define debug(...) (void)1
#endif

void force(){
	int n; i64 d;
	cin>>n>>d;
	vector<i64>a(n+1); 
	for(int i=1; i<=n; i++) cin>>a[i];
	vector<int>r(n+2),l(n+1);
	r[n]=n,l[1]=1;
	for(int i=n-1;i;i--) if(a[i]+d>=a[i+1]) r[i]=r[i+1]; else r[i]=i;
	for(int i=2;i<=n;i++) if(a[i]-d<=a[i-1]) l[i]=l[i-1]; else l[i]=i;
//	for(int i=1;i<=n;i++)cerr<<l[i]<<' '<<r[i]<<'\n'; 
	i64 res=0;
	vector<pair<int,int>>cd;
	for(int i=1; i<=n; i++){
		for(int len=3; len<=n; len++){
			int j=i+len;
			
//			debug(i,j);
			if(j>n) break;
			if(a[j]-a[i]<=d) continue;
			if(a[j]-a[i]>2*d) break;
			int k=i;
			while(a[k]-a[i]<=d) k++;
			k--;
			auto can=[&](int i,int k,int j){
				if(abs(a[k]-a[i])>d||abs(a[j]-a[k])>d||abs(a[k-1]-a[i])>d||abs(a[k-1]-a[j])>d) return false;
//				debug("fuck",i,k,j); 
				if(abs(a[k-2]-a[i])<=d&&abs(a[k-2]-a[j])<=d) return false;
				return true;
			};
//			debug(i,k,j);
			if(can(i,k,j)){
//				res+=1ll*(i-l[i]+1)*(r[i+3]-i-3+1);
				cd.emplace_back(i,j);
//				debug(i,j);
	//			lst=i;
			}
		}
	}
	int p=cd.size();
//	debug(p,res);
	for(auto [l,r]:cd) debug(l,r);	
	vector<int>tl(p+1),tr(p+1);
	for(int i=0; i<p; i++){
		int j=i-1;
		while(j>=0&&cd[j].first==cd[i].first) j--;
		tl[i]=max((j<0?1:cd[j].first+1),l[cd[i].first]);
		j=i+1;
		while(j<p&&cd[j].second==cd[i].second) j++;
		debug(tl[i],tr[i],i,cd[i].first,cd[i].second,j,p,n);
		tr[i]=min((j>=p?n:cd[j].second-1),r[cd[i].second]);
	}
	if(p){
		i64 left=cd[0].first-l[cd[0].first]+1;
		i64 right=min(r[cd[0].first],cd[1].second-1)-cd[0].second+1;
		debug(left,right);
		res+=left*right;
	}
	if(p>1){
		auto [ll,rr]=cd[p-1];
		i64 left=(ll-tl[p-1]+1),right=(tr[p-1]-rr+1);
//		i64 left=(cd[p-1].first-max(l[cd[p-1].first],min(cd[p-2].first+1,cd[p-1].first))+1),right=(r[cd[p-1].second]-cd[p-1].second+1);
		debug(left,right);
		res+=left*right;
	}
	for(int i=1;i<p-1;i++){
//		assert(false);
//		auto [l1,r1]=cd[i-1];
		auto [l2,r2]=cd[i];
		debug(l2,r2,i);
//		auto [l3,r3]=cd[i+1];
//		i64 left=(l2-max(min(l1+1,l2),l[l2])+1),right=(max(min(r3-1,r[r2]),r2)-r2+1);
		i64 left=(l2-tl[i]+1),right=(tr[i]-r2+1);
		debug(left,right,i,p);
		res+=left*right;
//		res+=1ll*(cd[i]-max(l[cd[i]],cd[i-1]+1)+1)*(min(r[cd[i]],cd[i+1]+2)-cd[i]-2);
	}
	cout<<res<<'\n';
}

void A(){
	 
}

void B(){
	int n,m; cin>>n>>m;
	vector<i64>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		
	}
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int c,t=1;
	cin>>c>>t;
	while(t--){
		if(c==11||c==12) A();
		else if(c==13||c==14) B();
		else force();
	} 
	return 0;
} 
