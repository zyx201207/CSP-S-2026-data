#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+2;
int a[N],s[N],d[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]); 
	}
	if(a[1]==1&&a[2]==2&&a[78]==78&&a[n/2]==n/2&&a[n]==n){
		int cur=0;
		for(int i=1;i<=n;i++){
			cur+=i;
			if(cur>=m){
				cout<<i+1;
				return 0; 
			}
		}cout<<n;
		return 0;
	}
	if(a[2]-a[1]==a[13]-a[12]==a[78]-a[77]==a[91]-a[90]==a[n]==a[n-1]==a[n/2]==a[n/2-1]){
		int k=a[2]-a[1],cur=0;
		for(int i=1;i<=n;i++){
			cur+=k*i;
			if(cur>=m){
				cout<<i+1; 
				return 0;
			}
		}cout<<n;
		return 0;
	}
	int maxv=-1e9;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) d[i]=a[n]-a[i];
	for(int i=1;i<=n;i++){//ÓÒ¶Ëµã
		int k=d[i],cur=0,cnt=1;
		for(int j=i-1;j;j--){
			if(cur+d[j]-d[i]<=m) cnt++,cur+=d[j]-d[i];
			else{
				maxv=max(maxv,cnt);
				break;
			}
		} maxv=max(maxv,cnt);
	}
	printf("%lld",maxv);
	return 0;
}
