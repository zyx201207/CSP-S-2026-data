#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sm[500005],mx;
int ck(int x,int i){
	return (a[i]*(i-x+1)-(sm[i]-sm[x-1]))<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		sm[i]=sm[i-1]+a[i];
		int l=1,r=i,ans=i;
		while (l<=r){
			int mid=l+r>>1;
			if (ck(mid,i)){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		mx=max(mx,i-ans+1);
	}
	cout<<mx;
} 
