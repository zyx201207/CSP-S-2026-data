#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,maxa=-1e18,a[N],p[N],cnt[N],ans=0,ii,vis[N],w[N];
bool isaii=1,isdcsl=1;
void dfs(ll c,ll ct){
	if(c>n){
		ll maxn=-1e18;
		for(int i=0;i<=45;i++){
			maxn=max(maxn,cnt[i]);
		}
		ans=max(maxn,ans);
		return;
	}
	for(int i=0;i<=ct;i++){
		p[c]=a[c]+i;
		cnt[p[c]+20]++;
		dfs(c+1,ct-i);
		cnt[p[c]+20]--;
		p[c]=0;
	}
	return;
}
void dfs1(ll c){
	if(c>n){
		if(ii<=ans){
			return;
		}
		ll maxn=0;
		for(int i=1;i<=ii;i++){
			maxn=max(maxn,p[i]);
		}
		ll need=0;
		for(int i=1;i<=ii;i++){
			need+=maxn-p[i];
		}
		if(need>m){
			return;
		}
//		cout<<"\n";
//		cout<<maxn;
		cout<<"\n";
		for(int i=1;i<=ii;i++){
			cout<<p[i]<<" ";
		} 
		cout<<"\n";
		ans=ii;
		return;
	}
	dfs1(c+1);
	p[++ii]=a[c];
	dfs1(c+1);
	p[ii--]=0;
	return;
}
int main(){
//	freopen("crystal2.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
		maxa=max(a[i],maxa);
		if(a[i]!=i)isaii=0;
		if(i!=1&&i!=2&&(abs(a[i]-a[i-1])!=abs(a[i-2]-a[i-1]))){
			isdcsl=0;
		}
	}
	if(n<=5&&m<=10&&maxa<=20){
		dfs(1,m);
		cout<<ans;
	}
	else if(n<=16&&m<=1000&&maxa<=20){
		dfs1(1);
		cout<<ans;
	}
	else if(isaii){
		int nw=1;
		ans=0;
		ll cnt=0;
//		while(m-nw>=0){
//			cnt++;
//			if(nw==1){
//				ans++;
//			}
//			ans++;
//			m-=nw;
//			nw++;
//		}
		if(m==0){
			cout<<0;
			return 0;
		}
//		cout<<ans;
		cout<<min((ll)((sqrt(1.0+8.0*m)-1.0)/2)+1,n);
	}
	else if(isdcsl){
		if(m==0){
			cout<<0;
			return 0;
		}
		ll gc=abs(a[1]-a[2]);
		cout<<min((ll)(sqrt(1.0+8.0*m*(1.0/gc))-1)*(2/gc)+1,n);
	}
	else{
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				w[i]+=a[i]-a[j];
			}
		}
		ll pos=upper_bound(w+1,w+1+n,m)-w-1;
//		ll npos=pos;
//		while(a[npos]==a[pos]){
//			npos++;
//		}
		cout<<pos;
//		ll l=1,r=n,mid;
//		while(l<r){
//			
//		}
	}
	return 0;
}
//10pts dfs每个水晶加1~m的值，最后计算O(m^n)
//20pts xxx先求出每个水晶离最近水晶的差值，dfs出水晶顺序全排列，然后一次性加满 
 

