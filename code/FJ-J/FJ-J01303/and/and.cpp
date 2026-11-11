#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool f1=1,f2=1,ff;
ll n,m,s,t,mx=-1,mn=1e18;
ll lj[4],p[32],vis[32],a[200005];
bool cmp(ll x,ll y){
	return x>y;
}
bool pd(ll x){
	for(int i=0;i<32;i++){
		if(x==p[i]-1){
			vis[i]++;
			return 1;
		} 
	}return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
//	freopen("and2.in","r",stdin);
//	freopen("and2.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=0;i<32;i++){
		p[i]=(1LL<<i);
	}
	
//	for(int i=0;i<32;i++){
//		cout<<p[i]<<' ';
//	}cout<<'\n';
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
		if(!pd(a[i])) f1=0;
		if(a[i]!=i-1) f2=0;
	}if(f1){
		ff=0;
		ll i=31;
		while(1){
			if(t==m) break;
			if(!vis[i]) i--;
			if(!ff&&vis[i]){
				s=p[i]-1;
				vis[i]--;
				ff=1;t++;
			}if(ff&&vis[i]){
				s&=(p[i]-1);
				vis[i]--;t++;
			}
		}cout<<s;
		return 0;
	}else if(f2){
		s=a[n];t++;
		for(int i=n-1;i>=1;i--){
			if(t==m) break;
			else s&=a[i],t++;
		}cout<<s;
		return 0;
	}else if(m==n-1){
		ff=0;
		for(int i=1;i<=n;i++){
			if(t==m) break;
			if(!ff&&a[i]!=mn){
				s=a[i];ff=1;t++;
			}if(ff&&a[i]!=mn){
				s&=a[i];t++;
			}
		}cout<<s;
		return 0;
	}else if(mx<4){
		ff=0;
		for(int i=1;i<=n;i++){
			lj[a[i]]++;
		}ll i=3;
		while(1){
			if(t==m) break;
			if(!lj[i]) i--;
			if(!ff&&lj[i]){
				s=i;lj[i]--;
				ff=1;t++;
			}if(ff&&lj[i]){
				s&=i;lj[i]--;t++;
			}
		}cout<<s;
		return 0;
	}else{
		sort(a+1,a+n+1,cmp);mx=-1;
		for(int i=1;i<=n-m+1;i++){
			s=a[i];
			for(int j=i+1;j<i+m;j++){
				s&=a[j];
			}mx=max(mx,s);
		}cout<<mx;
		return 0;
	}
	return 0;
}
