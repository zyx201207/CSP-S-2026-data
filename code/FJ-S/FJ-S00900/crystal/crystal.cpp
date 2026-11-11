#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ns[500005];
int l,r,mid,ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ns[i];
	}sort(ns+1,ns+1+n);
	for(int i=1;i<=n;i++){
		ns[i]+=ns[i-1];
		l=1,r=i-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(ns[i]-ns[mid-1]+m>=(ns[i]-ns[i-1])*(i-mid+1)){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-r);
	}cout<<ans;
	return 0;
}
