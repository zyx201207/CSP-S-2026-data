#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int n,m,ls[500010],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>ls[i];
	sort(ls,ls+n);
	for(int i=n;i>=1;i--) ls[i]-=ls[i-1];
	for(int i=n;i>=1;i--) ls[i]+=ls[i+1];
	for(int i=n;i>=1;i--) ls[i]+=ls[i+1];
	for(int i=2;i<=n;i++){
		int d=ls[i]-ls[i+1];
		int l=1,r=i-1;
		while(l<r){
			int mid=(l+r)/2;
			if(ls[mid]-ls[i]-(i-mid)*d>m) l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
