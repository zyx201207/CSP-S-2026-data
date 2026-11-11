//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,m;
//int cnt[500100];
//int check(int a){
//	int sum=0,oo=m;
//	int pl=upper_bound(cnt+1,cnt+1+n,a)-cnt-1;
//	for(int i=pl;i>=1;i--){
//		if()
//	}
//	return 1;
//}
//signed main(){
//	freopen("crystal4.in","r",stdin);//!!!!!!!!!!!!!!
//	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	cin>>n>>m;
//	int l=LLONG_MAX,r=LLONG_MIN,mid;
//	for(int i=1;i<=n;i++){
//		cin>>cnt[i];
////		l=min(l,cnt[i]);
////		r=max(r,cnt[i]);
//	}
//	sort(cnt+1,cnt+1+n);
//	l=cnt[1],r=cnt[n];
//	int s=1000;
//	while(l<=r){
//		mid=(l+r)>>1;
//		if(check(mid)==1){
//			l=mid+1;
//		}else r=mid-1;
//	}
//	// need to check
//	int aaa=l-1;
//	int ans=0;
//	for(int i=1;i<=n;i++){
//		if(cnt[i]<=aaa){
//			ans++;
//		}
//	}
//	cout<<ans;
//} 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int cnt[500100];
int sum[500100];
signed main(){
	freopen("crystal.in","r",stdin);//!!!!!!!!!!!!!!
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
	}
	sort(cnt+1,cnt+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+cnt[i];
	}
	int l=1,r=1;
	int ans=-1;
	while(r<=n&&l<=r){
		int zhi=sum[r]-sum[l-1];
//		cout<<l<<" "<<r<<" "<<cnt[r]*(r-l+1)-zhi<<"\n";
		if(cnt[r]*(r-l+1)-zhi>m){
			l++;
		}else{
		ans=max(ans,(r-l+1));
		 r++;}
	}
	cout<<ans;
} 
