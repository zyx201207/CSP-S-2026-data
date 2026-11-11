#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
int n,d,ans,x[N],cnt[N],fr[N];
int tot,lv[N],rv[N],val[N],sum[N],in[N];
void calc(int l,int r){
	if(r-l+1<3) return;
	for(int i=l-1;i<=r;i++) in[i]=0;
	int p=l;
	for(int i=l;i<=r;i++){
		while(p+1<=r&&x[p+1]-x[i]<=d) p++;
		cnt[i]=p-i,fr[i]=p;
		in[i+1]++,in[fr[i]+1]--;
	}
	for(int i=l;i<=r;i++) in[i]+=in[i-1];
	tot=0;
	int ll=l;
	while(ll<=r){
		int rr=ll;
		tot++;
		if((rr==l&&cnt[l]==1)||(rr+1<=r&&in[rr+1]==1)){
			while(rr+1<=r&&cnt[rr]==1) rr++;
			lv[tot]=x[ll],rv[tot]=x[rr],val[tot]=rr-ll+1;
			ll=rr+1;
		} 
		else{
			lv[tot]=x[ll],rv[tot]=x[ll],val[tot]=1;
			ll=rr+1;
		}
	}
	p=1;
	for(int i=1;i<=tot;i++){
		sum[i]=sum[i-1]+val[i];
		while(p+1<=tot&&lv[p+1]-rv[i]<=d) p++;
		cnt[i]=p-i,fr[i]=p;
	} 
	for(int i=1;i<tot;i++){
		if(cnt[i]<2) continue;
		int mx=cnt[fr[i]-1]-(cnt[fr[i]-2]-1);
		if(mx>0) ans+=val[i]*(sum[fr[fr[i]]]-sum[fr[fr[i]]-mx]);
	} 
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	int lst=1;
	for(int i=1;i<n;i++){
		if(x[i+1]-x[i]>d){
			calc(lst,i);
			lst=i+1;
		} 
	}
	calc(lst,n);
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
0
1

0 1
10 3
0 3 6 7 8 9 10 11 14 17
16

0 1
6 3
1 2 3 4 5 6
*/
