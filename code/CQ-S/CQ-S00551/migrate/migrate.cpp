#include<bits/stdc++.h>
#define int long long
#define N 2000010 
using namespace std;
int n,d,now,ans,tmp,maxn[N],lst[N],nxt[N],rr[N],x[N],a[N],b[N];
vector<int> v1[N],v[N];
void solve(){
	/*
	0 1
	6 2
	-4 -3 -2 -1 3 6
	
	0 1
	5 2
	1 2 3 4 5
	*/
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	now=1;
	for(int i=1;i<=n;i++){
		while(x[i]-x[now]>d) now++;
		if(now<=i) lst[i]=now;
		else lst[i]=-1e15;
	}
	now=n;
	for(int i=n;i>=1;i--){
		while(x[now]-x[i]>d) now--;
		if(now>=i) nxt[i]=now;
		else nxt[i]=1e15;
	} 
	int l,r,ll,rl,mid;
	for(int i=1;i<=n;i++){
		l=i,r=n,ll=-1;
		while(l<=r){
			mid=(l+r)/2;
			if(x[mid]-x[i]>d) ll=mid,r=mid-1;
			else l=mid+1;
		}
		rr[i]=-1;
		if(ll==-1) continue;
		rl=nxt[nxt[i]];
		if(rl==-1||ll>rl) continue;
		l=ll,r=rl;
		while(l<=r){
			mid=(l+r)/2;
			if(lst[mid]>i&&lst[mid]<nxt[i]&&nxt[i]<mid){
				rr[i]=mid;
				r=mid-1;
			}
			else l=mid+1;
		} 
	}
	ans=0;
	for(int i=1;i<=n;i++) v[i].clear(),v1[i].clear();
	for(int i=1;i<=n;i++) maxn[i]=1e15;
	for(int i=1;i<=n;i++) if(rr[i]!=-1) v[rr[i]].push_back(i),v1[i].push_back(rr[i]),maxn[i]=min(maxn[i],rr[i]);	
	tmp=0;a[0]=1;a[n+1]=n;
	for(int i=1;i<=n;i++){
		for(int it:v[i]) tmp=max(tmp,it);
		a[i]=tmp+1;
	}
	tmp=n+1;
	for(int i=n;i>=1;i--){
		for(int it:v1[i]) tmp=min(tmp,it);
		b[i]=tmp-1;
	}
	for(int i=1;i<=n;i++){
		if(rr[i]==-1) continue;
		for(int l=1;l<=i;l++){
			for(int r=rr[i];r<=n;r++){
				bool fl=0;
				for(int j=l;j<=r;j++){
					if(i==j) continue;
					if(maxn[j]>=r) fl=1;
				}
				if(fl==0) ans++;
			}
		}
	}
//	for(int i=1;i<=1;i++){
//		if(rr[i]!=-1){
//			ans=ans+(i-a[rr[i]]+1)*(b[i]+1-rr[i]);
//			cout<<(i-a[rr[i]]+1)<<"x"<<(b[i]+1-rr[i])<<"\n";
//		}
//	}
//	for(int i=1;i<=n;i++){
//		if(rr[i]!=-1){
//			cout<<i<<" ";
//		}
//	}
//	for(int i=1;i<=n;i++) cout<<rr[i]<<" ";
//	cout<<"\n";
	cout<<ans<<"\n"; 
//	for(int i=1;i<=n;i++) cout<<a[i]<<" "<<b[i]<<"\n";
//	return ;
	
	return ;
//	cout<<ans;
//	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	int tid,T;
	cin>>tid>>T;
	while(T--) solve(); 
	return 0;
} 
