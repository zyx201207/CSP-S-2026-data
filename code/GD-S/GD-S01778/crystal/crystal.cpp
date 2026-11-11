#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500006],sum[500006],Ans;
bool check(int l,int r){
	return (a[r]*(r-l+1)-(sum[r]-sum[l-1])) <= m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i <= n; i++)
		sum[i] = sum[i-1]+a[i];
	for(int i = 1;i <= n; i++){
		int l = i,r = n,pos = i;
		while(l <= r){
			int mid = (l+r)>>1;
			if(check(i,mid)){
				l = mid+1;
				pos = mid;
			}else r = mid-1;
		}
		Ans = max(Ans,pos-i+1); 
	}
	cout << Ans;
	return 0;
}
