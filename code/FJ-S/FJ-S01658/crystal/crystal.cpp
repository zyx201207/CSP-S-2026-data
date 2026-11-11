#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N=5e5+5;
int n,m,ans=1;
int a[N],pre[N];
#undef int
int main(){
	#define int long long
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,out=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(pre[i]-pre[mid]-(mid-1)*(a[i]-a[mid])<=m){
				out=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-out+1);
	}
	cout << ans;
	return 0;
}
