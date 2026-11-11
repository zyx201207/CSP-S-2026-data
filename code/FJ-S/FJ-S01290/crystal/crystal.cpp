#include <bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n;
long long m;
long long a[N];
long long b[N];
bool check(long long x){
	long long s=0;
	for(int i=1;i<=n;i++) s+=max((1ll-1),x-a[i]);
	return s<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long l=-1e12,r=1e12,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		r=max(r,a[i]);
//		l=min(l,a[i]);
	} 
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(ans>=a[i]) cnt++;
	cout<<cnt;
//	sort(a+1,a+n+1);
//	b[1]=0;
////	b[2]=a[2]-a[1];
////	b[3]=b[2]+(a[3]-a[2])*2;
////	for(int i=1;i<=n;i++) s1[i]=s1[i-1]+a[i];
////	for(int i=1;i<=n;i++) s[i]=s[i-1]+s1[i];
//	for(int i=1;i<=n;i++) b[i]=(a[i]-a[i-1])*(i-1);
//	int cnt=0,ans=0;
//	for(int i=1;i<=n;i++){
//		cnt++;
//		s[i]=s[i-1]+b[i];
//		if(s[i]>m){
//			b[i]=0;
//			ans=max(ans,cnt-1);
//			cnt=1;
//		}
//	} 
////	for(int i=1;i<=n;i++) s2[i]=s2[i-1]+b[i];
//	cout<<max(ans,cnt);
	return 0;
}


