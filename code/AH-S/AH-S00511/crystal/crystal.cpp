#include<bits/stdc++.h>
#define int long long
//#define DEBUG
#ifdef DEBUG
#define debug(x...) fprintf(stderr,x)
#else
#define debug(x...) ((void)0)
#endif
using namespace std;
int n,m;
int a[500005];
int s[500005];
bool check(int x,int i){
	return a[i]*(i-x+1)-(s[i]-s[x-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=i;j++){
	//		debug("%lld %lld %d\n",j,i,check(j,i));
	//	}
	//}
	int res=0;
	for(int i=1;i<=n;i++){
		int L=1,R=i,ans=-1;
		while(L<=R){
			int mid=(L+R)/2;
			if(check(mid,i)){
				ans=mid;
				R=mid-1;
			}else L=mid+1;
		}
		if(ans!=-1) res=max(res,i-ans+1);
	}
	cout<<res<<endl;
	return 0;
}
