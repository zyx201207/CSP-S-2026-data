#include<bits/stdc++.h>
#include<bits/stl_set.h>
using namespace std;
long long n,m,a[500008],maxn=-0x3f3f3f3f;
//int d[500008],pre[500008],l=-1,r=-1,
//bool check(int l,int r){
//	int t=a[r],s=0;
//	for(int i=l;i<r;i++){
//		s+=t-a[i];
//	}
//	return s;
//	if(s<=m){
//		return true;
//	}else{
//		return false;
//	}
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		if(i!=1){
//			if(l==-1&&a[i-1]>a[i]){
//				l=i;
//			}
//			if(l!=-1&&a[i-1]>a[i]){
//				r=i-1;
//				if(check(l,r)){
//					maxn=max(maxn,r-l+1);
//				}
//				l=i,r=-1;
//			}
//		}
	}
	if(n<=5000){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			long long s=0;
			for(int j=1;j<=i;j++){
				s+=a[i]-a[j];
			}
			if(s<=m){
				maxn=max(maxn,1ll*i);
			}
		}
		cout<<maxn;
		return 0;
	}
	int s;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s+=abs(a[i])-1;
		if(s==m){
			cout<<i+1;
			return 0;
		}
		if(s>m){
			cout<<i;
			return 0;
		}
	}
	cout<<n;
//	sort(a+1,a+n+1);
//	for(int i=2;i<=n;i++){
//		d[i]=a[i]-a[i-1];
//	} 
//	long long ans;
//	for(int i=2;i<=n;i++){
//		pre[i]=pre[i-1]+d[i];
//		if(pre[i]<=m){
//			ans=i;
//		}
//	}
//	cout<<ans;
	return 0;
}
/*
我不甘心！
CCF还我J组T1 100分！！！
ABCDF 
*/
