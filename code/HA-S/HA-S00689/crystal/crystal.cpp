#include<bits/stdc++.h>

using namespace std;
/*
// 二分答案罢
// 好像不是
//
// 答案到底是不是单调的
// 好像不是
//
// 一个诡异思路?
// 维护一个最大上凸包,然后往里面填点?
// 似乎是不对的
//
// 贪心地合并差距最小的两根柱子?
*/
#define maxn 500005
#define ll long long
int n;
ll a[maxn],m,sum[maxn],ans=1;//hep[maxn],val[maxn],siz[maxn],
//int frt[maxn],bac[maxn],st[maxn],ed[maxn];
priority_queue<pair<ll,int> ,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
//bool check(int i){
//
//}

//pair<ll,ll> 
ll aver(int l,int r){
	ll sumn=sum[r]-sum[l-1],len=r-l+1;
//	cerr<<"AV"<<sumn<<' '<<len<<'\n';
	return (sumn-1)/len+1;
//	return {sumn/len,sumn/len+1};
}

signed main() {
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);sum[1] = a[1];
	int l=1;
	ll sumw=0,hep = a[1];
	for(int r=2;r<=n;r++){
		sum[r] = sum[r-1] + a[r];
//		cerr<<r<<'\n';
		auto av=aver(l,r);
		ll len=r-l+1,qw  = sumw + len*(av-hep) + (a[r] - av);//qw = min(sumw + len*(av.first-hep) + (a[r] - av.first),sumw + len*(av.second-hep) + (a[r] - av.second));
//		ll rav = (sumw + len*(av.first-hep) + (a[r] - av.first) >= sumw + len*(av.second-hep) + (a[r] - av.second))?av.second:av.first;
//		cerr<<av.first<<' '<<av.second<<'\n';
//		cerr<<l<<' '<<r<<' '<<av<<' '<<qw<<'\n';
//	cerr<<"F1\n";
		if(qw<=m ){
			
//	cerr<<"f0\n";
			hep = av,sumw +=len*(av-hep) + (a[r] - av);
		}else{
			
//	cerr<<"f2\n";
			do{
				sumw -= hep - a[l];
				len++,l++,av=aver(l,r),qw  = sumw + len*(av-hep) + (a[r] - av);//qw=min(sumw + len*(av.first-hep) + (a[r] - av.first),sumw + len*(av.second-hep) + (a[r] - av.second));
//				rav = (sumw + len*(av.first-hep) + (a[r] - av.first) >= sumw + len*(av.second-hep) + (a[r] - av.second))?av.second:av.first;
//				cerr<<av.first<<' '<<av.second<<'\n';
//				cerr<<l<<' '<<r<<' '<<av<<' '<<qw<<'\n';
			}while(l<r&&qw>m);
			
//	cerr<<"F3\n";
			if(l==r){
				len=1,sumw=0,hep=a[r];
			}else{
				hep = av,sumw = qw;
			}
		}
		ans = max(ans,len);
	}
	cout<<ans;
//	for(int i=1;i<n;i++){
//		sum[i] = sum[i-1]+a[i];
//		pq.push({a[i+1]-a[i],i});
//		val[i] = a[i+1] - a[i],hep[i] = a[i],
//		frt[i]=i-1,bac[i]=i+1,
//		st[i] = ed[i] = i; 
//	}
//	while(!pq.empty()){
//		auto [v,i] = pq.top();
//		pq.pop();
//		if(val[i]!=v) continue;
//		siz[++n] = siz[i] + siz[bac[i]],
//		frt[n] = frt[i] , bac[n] = bac[bac[i]],
//		st[n] = st[i],ed[n] = ed[bac[i]],
//		val[bac[i]] = -1,hep[n] = 1.0*(sum[ed[n]] - sum[st[n]-1]) / 
//		val[n] = 
//	}
//	ll l=0,r=1000000000000ll,ans=0;
//	while(l<=r){
//		ll mid=(r+l)>>1;
//		if(check(mid)){
//			ans=mid,r=mid-1;
//		}else{
//
//		}
//	}


	return 0;
}
