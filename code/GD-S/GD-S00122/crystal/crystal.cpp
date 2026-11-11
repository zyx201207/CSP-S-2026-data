#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int res=0;
	for(int i=1;i<=n;i++){
		int x=a[i],l=1,r=i-1;
		while(l<r){
			int mid=(l+r)>>1;
			int k=(i-mid)*x-s[i-1]+s[mid-1];
			if(k<=m&&k>=0)r=mid;
			else l=mid+1;
		}
		res=max(res,i-l+1);
	}
	cout<<res;
}
