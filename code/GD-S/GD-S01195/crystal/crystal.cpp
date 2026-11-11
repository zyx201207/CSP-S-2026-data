#include<bits/stdc++.h>
using namespace std;
#define int long long
#define first fs
#define second sc
#define rep(i,l,r) for(int i=l;i<=(r);i++)
const int N=5e5+9;
int A[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	rep(i,1,n)cin>>A[i];
	sort(A+1,A+n+1);
	int Cost=0,l=1,ans=0;
	rep(r,1,n){
		Cost+=(r-l)*(A[r]-A[r-1]);
		while(Cost>m and l<r)Cost-=A[r]-A[l],l++;
		ans=max(ans,r-l+1);
	} 
	cout<<ans;
	return 0;
}
/*
显然可以枚举或贪心，我认为前者是稳妥的。
没有多测，双指针考虑即可。 
Oct31==Dec25?

*/
