#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mr make_pair
#define pb push_back
#define fr front
//#define ins insert
#define pp pop_back
#define p_queue prioriry_queue
using namespace std;
int a[510000];
int n,m;
int zu[510000];
int cu[510000];//->
int eu[510000];//<-
int sq[510000];//<-
int sp[510000];//1 -> n
int hou(int l,int r){
//	int tot=l;
//	r++;
	l++;
	int l2=r+1;
//	int l1=l,l2=r;
	int h=(n-l+1)-(r-l+1);
	int ans=sq[l]-((eu[l]-eu[r+1])*h+sq[l2]);
	return ans;
}int qian(int l,int r){
	r--;
	int r2=l-1;
	int h=r-(r-l+1);
	int ans=sp[r]-((cu[r]-cu[l-1])*h+sp[r2]);
	return ans;
}
bool check(int x){
	if(x<=1){
		return true;
	}int o=x/2;
	if(x&1){
		int ll=1,rr=x;
		int mid;
		while(rr<=n){
			int zs=qian(ll,rr);
//			mid=(ll+rr)>>1;
//			int zs=qian(ll,mid)+hou(mid,rr);
			if(zs<=m){
//				cout<<ll<<" "<<rr<<" OK\n";
				return true;
			}
			ll++;
			rr++;
		}return false;
//		for(int i=o+1;i<=n-o-1;i++){
//			int l=i-o;
//			int r=i+o;
//			int zs=qian(l,i-1)+hou(i+1,r);
////			cout<<x<<" :\n";
////cout<<l<<" "<<i<<" "<<r<<"\n";
////cout<<qian(l,i)<<" "<<hou(i,r)<<"\n";
//			if(zs<=m){
//				return true;
//			}
//		}return false;
	}else{
		int ll=1,rr=x;
		int mid;
		while(rr<=n){
			int zs=qian(ll,rr);
//			mid=(ll+rr)>>1;
//			int zs=qian(ll,mid)+hou(mid,rr);
//			mid++;
//			zs=min(zs,qian(ll,mid)+hou(mid,rr));
			if(zs<=m){
				return true;
			}ll++;
			rr++;
		}return false;
//		for(int i=x;i<=n;i++){
//			int zs=2e18;
//			int l=i-o+1;
//			int r=i+o;
//			if(r<=n&&l>0){
////				cout<<x<<" :\n";
////	cout<<l<<" "<<i<<" "<<r<<"\n";
////	cout<<qian(l,i)<<" "<<hou(i,r)<<"\n";
//				zs=min(zs,qian(l,i)+hou(i,r));
//			}l=i-o;
//			r=i+o-1;
//			if(r<=n&&l>0){
////				cout<<x<<" :\n";
////	cout<<l<<" "<<i<<" "<<r<<"\n";
////	cout<<qian(l,i)<<" "<<hou(i,r)<<"\n";
//				zs=min(zs,qian(l,i)+hou(i,r)); 
//			}
//			if(zs<=m){
//				return true;
//			}
//		}return false;
	}
}signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	int cnt=1;
	for(int i=1;i<=n;i++){
		zu[i]=a[i]-a[i-1];
	}for(int i=1;i<=n;i++){
		sp[i]=sp[i-1]+cnt*zu[i+1];//->
		cu[i]=cu[i-1]+zu[i+1];//->
		cnt++;
	}cnt=1;
	for(int i=n;i>=1;i--){
		eu[i]=eu[i+1]+zu[i];//<-
		sq[i]=sq[i+1]+cnt*zu[i];//<-
		cnt++;
	}
//	for(int i=1;i<=n;i++){
//		cout<<sq[i]<<" ";
//	}
//	cout<<"\n";
//	int to=10;
//	int l,r;
//	while(to--){
//		cin>>l>>r;
//		cout<<hou(l,r)<<endl;
//	}
//	return 0;
	int l=1,r=n;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}cout<<r<<"\n";
	return 0;
}/*
Thanks for Tad reminding us to check out freopen and debug code.
Luckily,I find a bug when I only have 15 min.
I believe I can AC T1.
Bless me.
*/

