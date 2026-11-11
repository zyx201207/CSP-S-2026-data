#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mem(a,b) memset(a,b,sizeof(a))
#define For(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
#define Gor(i,a,b) for (int (i)=(a);(i)>=(b);(i)--)
using namespace std;
const int N=5e5+10,inf=2e18;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS
	cin >> n >> m;
	For(i,1,n){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	For(i,1,n){
		s[i]=s[i-1]+a[i];
		int l=1,r=i,res=1;
		while (l<=r){
			int mid=(l+r)/2;
			if (mid*a[i]-(s[i]-s[i-mid])<=m) res=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,res);
	}
	cout << ans;
}
