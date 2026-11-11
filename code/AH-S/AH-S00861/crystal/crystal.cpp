#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int maxn=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int mid=(l+r)/2;
		while(l<=r){
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1])>m) l=mid+1;
			else r=mid-1;
			mid=(l+r)/2;
		}
		int t=i-l+1;
		maxn=max(maxn,t);
	}
	cout<<maxn;
	return 0;
}
