#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int maxx=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	for(int i=2;i<=n;i++){
		if(a[i]+a[i-1]+m<a[i]*2){
			continue;
		}
		int l=1,r=i-1;
		while(l<r){
			int mid=l+r>>1;
			if(a[i]-a[mid-1]+m>=(a[i]-a[i-1])*(i-mid+1)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		maxx=max(maxx,i-l+1);
	}
	cout<<maxx;
	return 0;
} 
