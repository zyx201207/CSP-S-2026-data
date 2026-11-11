//GZ-S00050，阮辰允，贵阳市白云区华师一学校 
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define int long long
int n,m,a[500001],sum[500001],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,pos;
		while(l<=r){
			int mid=(l+r)>>1ll;
			if(a[mid]*(mid-i+1)-sum[mid]+sum[i-1]<=m){
				pos=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,pos-i+1);
	}
	cout<<ans;
	return 0;
}
