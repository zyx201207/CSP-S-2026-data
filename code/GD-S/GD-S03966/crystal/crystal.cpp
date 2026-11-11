#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500005];
int l=1,r;
bool check(int x){
	int minn,cnt=0,ll=1;
	for(int i=1;i<x;i++){
		cnt+=(a[x]-a[i]);
	}
	minn=cnt;
	for(int i=x+1;i<=n;i++){
		cnt-=(a[i-1]-a[ll]);
		ll++;
		cnt+=(x-1)*(a[i]-a[i-1]);
		minn=min(minn,cnt);
	}
	return minn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    r=n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(l<=r){
		int mid=(l+r)>>1;
		int c=mid;
		if(check(mid)){
			ans=c;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
