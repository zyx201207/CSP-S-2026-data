#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+500;
int n,m,a[N],sum[N],ans=1;
bool check(int l,int r,int x){
	if((r-l+1)*x-(sum[r]-sum[l-1])<=m) return 1;
	return 0;
}
int GG_Bound(int l,int r,int x){
	int res=0,mid=0,rr=r;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid,rr,x)) res=mid,r=mid-1;
		else l=mid+1;
	}return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=0;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int pos=GG_Bound(1,i,a[i]);
		ans=max(ans,i-pos+1);
	}cout<<ans;
	return 0;
}
/*
14:45:35   AC
15:59:47  厕所归来，认为CCF不卡常，把inline去掉了
17:42:37  检查：数组越界、未定义行为、未初始化变量、数组大小 
期望得分100
预估难度：橙
已检查freopen 
*/
