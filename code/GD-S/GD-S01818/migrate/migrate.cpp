#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int n,m,a[maxn],ans,pre[maxn],suf[maxn],apre[maxn],asuf[maxn],tl[maxn],tr[maxn],bl[maxn],br[maxn];
int find1(int x){//找到第一个可以到达x 
	if(a[x]-a[1]<=m)return 1;
	if(a[x]-a[x-1]>m)return x;
	int l=1,r=x-1,mid;
	while(l<r){
		mid=l+r>>1;
		if(a[x]-a[mid]<=m)r=mid;
		else l=mid+1;
	}
	return l;
}
int find2(int x){//找到最后一个不能到达x 
	if(a[x]-a[1]<=m)return 0;
	if(a[x]-a[x-1]>m)return x-1;
	int l=1,r=x-1,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(a[x]-a[mid]>m)l=mid;
		else r=mid-1;
	}
	return l;
}
int find3(int x){//找到最后一个可以到达x 
	if(a[n]-a[x]<=m)return n;
	if(a[x+1]-a[x]>m)return x;
	int l=x+1,r=n,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(a[mid]-a[x]<=m)l=mid;
		else r=mid-1;
	} 
	return l;
}
int find4(int x){//找到第一个不能到达x 
	if(a[n]-a[x]<=m)return n+1;
	if(a[x+1]-a[x]>m)return x+1;
	int l=x+1,r=n,mid;
	while(l<r){
		mid=l+r>>1;
		if(a[mid]-a[x]>m)r=mid;
		else l=mid+1;
	}
	return l;
}
void solve(){
	ans=0;
	cin>>n>>m;
	for(int i=0;i<=n+2;i++)tl[i]=tr[i]=bl[i]=br[i]=apre[i]=asuf[i]=pre[i]=suf[i]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
//	cerr<<"pre:\n";
	for(int i=2;i<n;i++){ 
		int l=find1(i),r=find2(i+1);
		if(r==i)r--;
		if(l>r)continue;
		apre[i]=pre[i]=(r-l+1);
		if(r==i-1)apre[i]--;
		bl[i]=apre[i];
		tl[i]=l;
		pre[i]+=pre[l];
		if(l!=i-1)apre[i]+=pre[l];
//		cerr<<i<<" "<<l<<" "<<r<<" "<<pre[i]<<" "<<apre[i]<<"\n";
	}
//	cerr<<"suf:\n";
	for(int i=n-1;i>=2;i--){
		int l=find4(i-1),r=find3(i);
		if(l==i)l++;
		if(l>r)continue;
		asuf[i]=suf[i]=(r-l+1);
		if(l==i+1)asuf[i]--;
		br[i]=asuf[i];
		tr[i]=r;
		suf[i]+=suf[r];	
		if(r!=i+1)asuf[i]+=suf[r];
//		cerr<<i<<" "<<l<<" "<<r<<" "<<suf[r]<<"\n";
	}
//	for(int i=1;i<=n;i++)cerr<<tl[i]<<" "<<tr[i]<<"\n";
//	for(int i=2;i<=n;i++)cerr<<"a["<<i<<"]-a["<<i-1<<"]="<<a[i]-a[i-1]<<"\n";
//	for(int i=1;i<=n;i++)cerr<<pre[i]<<" ";
//	cerr<<"\n";
//	for(int i=1;i<=n;i++)cerr<<suf[i]<<" ";
//	cerr<<"\n";
	for(int i=1;i<=n-1;i++){//处理只能经过i与i+1的 
		//要求：[l1->r1]中每个点可以到i+1,不能到i+2
		//		[l2->r2]中每个点可以到i,  不能到i-1 
//		cerr<<i<<" "<<apre[i+1]<<" "<<asuf[i]<<"\n";
		int dl,dr;
		if(tl[i+1]==1||a[i]-a[tl[i+1]-1]>m)dl=apre[i+1];
		else dl=bl[i+1];
		if(tr[i]==n||a[tr[i]+1]-a[i+1]>m)dr=asuf[i];
		else dr=br[i];
		ans+=(dl*dr);
//		ans+=(apre[i+1]*asuf[i]);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _,__;
	cin>>_>>__;
	while(__--)solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

*/

