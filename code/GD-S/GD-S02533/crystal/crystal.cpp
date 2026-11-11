#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int MAXN=5e5+5;
int n,m,a[MAXN],s[MAXN];
bool check(int l,int r){
	int len=r-l+1;
	int sum=len*a[r];
	int now=s[r]-s[l-1];
	return sum-now<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				res=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
/*
T1 crystal
排序
求前缀和 
在a中枚举目标值 
在1~i中二分mid~i相同 
100pts
*/
