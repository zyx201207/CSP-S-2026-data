//#include<bits/stdc++.h>
//17:24 注意到数据范围qwq
//炸了 
//using namespace std;
//const int MAXN=5e5+5;
//#define int long long
//int a[MAXN];
//int n,m;
//int sum=0;
//int dif[MAXN];
//int pre[MAXN];
//int npre[MAXN];
//int ans=0;
//int Find(int x,int s){
//	int l=s,r=n;
//	int res=0;
//	while(l<=r){
//		int mid=(l+r)/2;
//		if(pre[mid]-(npre[mid]-npre[s])*(s-1)<=m){
//		if(pre[mid]<=m){
//			res=mid;
//			l=mid+1;
//		}
//		else{
//			r=mid-1;
//		}
//	}
//	return res;
//}
//signed main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	scanf("%lld %lld",&n,&m);
//	for(int i=1;i<=n;i++){
//		scanf("%lld",&a[i]);
//	}
//	sort(a+1,a+n+1);
//	for(int i=2;i<=n;i++){
//		dif[i]=a[i]-a[i-1];
//	}
//	for(int i=1;i<=n;i++){
//		pre[i]=pre[i-1]+dif[i]*(i-1);
//		npre[i]=npre[i-1]+dif[i];
//	}
//	for(int s=1;s<=n;s++){
//		for(int i=s;i<=n;i++) pre[i]=pre[i-1]+dif[i]*(i-1)-dif[i]*(s-1);
//		int val=Find(m,s);
//		ans=max(val-s+1,ans);
//		cout<<s<<" "<<ans<<"\n";
//		if(ans+s==m) break;
//	}
//	printf("%d\n",ans);
//} 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
#define int long long
int a[MAXN];
int n,m;
int ans=0;
int pre[MAXN];
int dif[MAXN];
int prepre[MAXN];
int Find(int x,int s){
	int l=s,r=n;
	int res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(pre[mid]<=m){
			res=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return res;
}
bool check(int x,int s){
	for(int i=1;i+x-1<=n;i++){
		if(s==1){
			__int128 s=(a[i+x-1])*x;
			if(s-pre[i+x-1]+pre[i-1]<=m){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			int res=pre[x]*x;
			if(res-prepre[x]+prepre[i-1]<=m) return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cnt+=a[i];
	}
	sort(a+1,a+n+1);
	dif[1]=0;
	for(int i=2;i<=n;i++){
		dif[i]=a[i]-a[i-1];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]+dif[i]*(i-1);
		}
		for(int s=1;s<=n;s++){
			for(int i=s;i<=n;i++) pre[i]=pre[i-1]+dif[i]*(i-s);
			int val=Find(m,s);
			ans=max(val-s+1,ans);
			if(ans+s==m) break;
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(cnt>0){
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]+a[i];
		}
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid,1)){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+dif[i];
	}
	for(int i=1;i<=n;i++){
		prepre[i]=prepre[i-1]+pre[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid,2)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
} 
