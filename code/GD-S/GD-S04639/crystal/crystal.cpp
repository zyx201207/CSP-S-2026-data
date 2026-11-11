#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
#define int long long
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i = 1; i <= n; i++){
		int l = i,r = n,res = -1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid]*(mid-i+1)-s[mid]+s[i-1]<=m){
				res=mid;l=mid+1;
			}
			else r=mid-1;
		}
		ans=max(ans,res-i+1); 
	}
	cout << ans;
}
