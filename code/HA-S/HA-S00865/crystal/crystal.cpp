#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=5e5+114;
ll ls[N],prsm[N];
int n;
ll m;
inline ll sum(int l,int r){
	return prsm[r]-prsm[l-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ls[i];
	}
	sort(ls+1,ls+n+1);
	for(int i=1;i<=n;i++){
		prsm[i]=prsm[i-1]+ls[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if((ll)(i-mid+1)*ls[i]-sum(mid,i)<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 500000000000003
-500000000000000 0 500000000000000 0 1
*/
