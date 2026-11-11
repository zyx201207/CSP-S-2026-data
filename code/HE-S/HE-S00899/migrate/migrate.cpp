#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int cas,T,n,d,ans;
int x[N],nxt[N],w[N];
void clear(){
	ans=0;
}
void casea(){
	int cha=x[2]-x[1];
	int cou=d/cha;
	if(cou==1){
		cout<<"0\n";
		return;
	}
	int res=0;
	for(int i=cou+1;i<=n;i++){
		if(i%cou==cou-1ll){
			res+=n-i;
		}
	}
	cout<<res<<"\n";
}
bool check(int l,int r){
	if(nxt[l]>=r){
		if(nxt[l]-1>=r) return 0;
		else{
			return 1;
		}
	}else{
		for(int i=l;i<=r;i=nxt[i]){
			if(nxt[i-1]>=nxt[i]) return 0;
		}
		return 1;
	}
}
signed main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>cas>>T;
	while(T--){
		cin>>n>>d;
		clear();
		if(n==1){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
//			if(i!=1) c[i]=x[i]-x[i-1];
//			if(i!=1) q[i]=q[i-1]+c[i];
		}
//		casea();
		if(cas==11||cas==12){
			casea();
			continue;
		}
		nxt[n]=n+1;
		for(int i=1;i<n;i++){
			int l=i+1,r=n,res;
			while(l<=r){
				int mid=(l+r)>>1;
				if(x[i]+d>=x[mid]){
					res=mid;
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			nxt[i]=res;
		}
		w[n]=0;
		for(int i=n-1;i>=1;i--){
			w[i]=w[nxt[i]]+1;
		}
		for(int i=n-1;i>=1;i--){
			int nx=nxt[i];
			int rmx=nxt[nx],r=nxt[nx-1],l=nxt[nx-2]+1;
			l=max(l,nx+1);
			if(l>r) continue;
			ans+=r-l+1;
			if(r!=rmx) continue;
			int ll=rmx,rr=n,res=ll;
			while(ll<=rr){
				int mid=(ll+rr)>>1;
				if(check(ll,mid)){
					res=mid;
					ll=mid+1;
				}else{
					rr=mid-1;
				}
			}
			ans+=res-rmx;
		}
		cout<<ans<<"\n";
	}

	return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6

fc migrate.out migrate4.ans
*/

