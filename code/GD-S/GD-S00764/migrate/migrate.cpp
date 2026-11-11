#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,d,T;
const ll N=2e6+10,M=5010,inf=2e9;
vector<ll>e[N];
ll x[N],dis[N],num[N];
void adde(ll u,ll v){
	e[u].emplace_back(v);
	e[v].emplace_back(u);
}
void sub1(){
	for(ll i=1;i<=n;i++)e[i].clear();
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(j>i&&abs(x[i]-x[j])<=d)adde(i,j);
		}
	}
	ll ans=0;
	queue<ll>q;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++)dis[j]=inf,num[j]=0;
		dis[i]=0,num[i]=1;
		q.emplace(i);
		while(q.size()){
			ll u=q.front();q.pop();
			if(num[u]>2)continue;
			for(ll v:e[u]){
				if(num[v]>2)continue;
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					num[v]=1;
					q.emplace(v);
					continue;
				}
				else if(dis[v]==dis[u]+1){
					num[v]++;
					q.emplace(v);
				}
			}
		}
		for(ll j=1;j<=n;j++)if(num[j]==2)ans++;
	}
	cout<<ans/2<<"\n";
}
//------------------------------------------------
ll L[N],R[N];
struct fenwick_tree{
	vector<ll>tr;
	ll L;
	void set(ll _){
		L=_;
		tr.resize(L+2);
		for(ll i=1;i<=L;i++)tr[i]=0;
	}
	#define low(i) (i&-i)
	void add(ll i,ll k){
		for(;i<=L;i+=low(i))tr[i]+=k;
	}
	ll ask(ll i){
		ll res=0;
		for(;i;i-=low(i))res+=tr[i];
		return res;
	}
	ll get(ll l,ll r){
		if(l>r)return 0;
		return ask(r)-ask(l-1);
	}
}tr;
void sub2(){
//	for(ll i=1;i<=n;i++){
//		ll l=1,r=i,res=i;
//		while(l<=r){
//			ll mid=(l+r)>>1;
//			if(abs(x[i]-x[mid])<=d)res=mid,r=mid-1;
//			else l=mid+1;
//		}
//		L[i]=res;
//		l=i,r=n;
//		while(l<=r){
//			ll mid=(l+r)>>1;
//			if(abs(x[i]-x[mid])<=d)res=mid,l=mid+1;
//			else r=mid-1;
//		}
//		R[i]=res;
//		cout<<L[i]<<" "<<R[i]<<"\n";
//	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll left=i,right=i;
		tr.set(n);
		tr.add(i,1);
		while(left>1||right<n){
			ll nxtl=L[left],nxtr=R[right];
			if(nxtl==left&&nxtr==right)break;
			for(ll j=nxtl;j<left;j++){
				tr.add(j,tr.get(left,min(R[j],right)));
			}
			for(ll j=right+1;j<=nxtr;j++){
				tr.add(j,tr.get(max(L[j],left),right));
			}
			left=nxtl,right=nxtr;
		}
		for(ll j=left;j<=right;j++)if(tr.get(j,j)==2)ans++;
//		cout<<"at "<<i<<"\n";
//		for(ll j=1;j<=n;j++)cout<<tr.get(j,j)<<" ";
//		cout<<"\n----------\n";
	}
	cout<<ans/2<<"\n";
}
ll atl[N],atr[N];
void sub3(){
	ll ans=0;
	for(ll i=1;i<=n;i++)atl[i]=atr[i]=0;
	for(ll i=1;i<=n;i++){
		cout<<L[i]<<" "<<R[i]<<"\n";
		if(L[i]==1&&R[i]==n)continue;
		if(L[i]!=i)atl[L[i]]++;
		if(R[i]!=i)atr[R[i]]++;
	}
	for(ll i=1;i<=n;i++){
		if(R[i]!=n||L[i]!=1){
			ans+=atl[i]*atr[i];
			cout<<"here "<<i<<" "<<atl[i]<<" "<<atr[i]<<"\n";
		}
	}
	cout<<ans<<"\n";
}/*
13 1
6 5
0 1 2 5 7 9 10  

*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>T;
	L[0]=1,R[0]=1;
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i];
		for(ll i=1;i<=n;i++){
			L[i]=L[i-1],R[i]=max(i,R[i-1]);
			while(L[i]<=i&&abs(x[i]-x[L[i]])>d)L[i]++;
			while(R[i]<n&&abs(x[R[i]+1]-x[i])<=d)R[i]++;
		}
		if(c<=6){sub1();continue;}
		if(c>6&&c<=10){sub2();continue;}
		if(c==13||c==14){sub3();continue;}
	}
	return 0;
} /*
----------------------
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
----------------------
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
----------------------
0 1
5 3
-3 0 2 3 4

2
*/
