#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=500005;
int a[N];
int s[N];
int n,m;
int get(int l,int r){
	return s[r]-s[l-1];
}
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		int c=a[i+x-1]*x-get(i,i+x-1);
		if(c<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=0;
	int r=N;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
} 
