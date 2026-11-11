#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[500005];
int s[500005];
int check(int x,int y){
	return (a[y]*(y-x+1)-s[y]+s[x-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,num;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)) r=mid-1,num=mid;
			else l=mid+1;
		}
		ans=max(ans,i-num+1);
	}
	cout<<ans;
	return 0;
}
