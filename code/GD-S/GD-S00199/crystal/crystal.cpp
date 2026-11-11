#include<bits/stdc++.h>
#define x0 x_0
#define x1 x_1
#define y0 y_0
#define y1 y_1
#define yn y_n
#define j0 j_0
#define j1 j_1
#define jn j_n
#define k0 k_0
#define k1 k_1
#define d0 d_0
#define d1 d_1
#define LL long long
#define LD long double
#define Big __int128
#define STR string
#define US unsigned
#define ZPB push_back
#define ZPF push_front
#define PPB pop_back
#define PPF pop_front
#define next NXTNXT
#define UPB upper_bound
#define LWB lower_bound
#define mem(x,val) memset(x,val,sizeof(x))
using namespace std;
const int N=500010;
int n,ans;
LL a[N],sum[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int r=i;
		while(r<n && a[r+1]==a[i]) ++r;
		int L=1,R=i-1,res=i;
		while(L<=R){
			int mid=(L+R)>>1;
			// [mid,i-1]
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m) res=mid,R=mid-1;
			else L=mid+1;
		}
		ans=max(ans,r-res+1),i=r;
	}
	cout<<ans<<"\n";
	return 0;
}

/*
input1:

5 5
1 2 4 8 9

output1:

3

input2:

5 8
-3 -1 2 2 7

output2:

4
*/
