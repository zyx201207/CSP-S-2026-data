#include<bits/stdc++.h>
#define N 500050
#define int long long
using namespace std;
int n,m;
int a[N],s[N];
int f(int l,int x){
	return (l-1)*a[x]-(s[x-1]-s[x-l]);
}
bool chk(int l,int x){
	if(f(l,x)<=m) return 1;
	return 0;
}
int find(int x){
	int l=1,r=x,mid=0,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(chk(mid,x)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	return ans;
}//二分长度 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0,pos=0;
	for(int i=1;i<=n;i++){
		int now=find(i);
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}

