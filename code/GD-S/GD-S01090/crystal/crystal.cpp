#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define pb push_back
#define V vector
const int N=5e5+10;
int a[N],sum[N];
int getsum(int l,int r){
	return sum[r]-sum[l-1];
}
int tobe(int l,int r,int val){//代价 
	int fsum=getsum(l,r);//原先的 
	int tsum=val*(r-l+1);//要成为的 
	return tsum-fsum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int n,m;cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	FOR(i,1,n)sum[i]=sum[i-1]+a[i];
	int ans=0;
	FOR(i,1,n){
		int val=a[i];
		int l=1,r=i,tmp=0;
		while(l<=r){
			int len=(l+r)>>1;
			int idx=i-len+1;
			if(tobe(idx,i,val)<=m){
				l=len+1;
				tmp=len;
			}else r=len-1;
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/
