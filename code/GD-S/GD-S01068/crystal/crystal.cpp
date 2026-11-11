#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
int a[500004];
int pre[500004];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int lin=0;
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			int L=mid-i+1;
			lin=(L-1)*a[mid]-(pre[mid-1]-pre[i-1]);
			if(lin<=m) l=mid;
			else r=mid-1;
		}
		ans=max(ans,r-i+1);
	}
	cout<<ans;
	return 0;
} 

