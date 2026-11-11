#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
int n,m,a[N],ans,s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,k=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])>m){
				l=mid+1;
			}else{
				r=mid-1;
				k=mid;
			}
		}
		ans=max(ans,i-k+1);
	}
	cout<<ans;
	return 0;
}
