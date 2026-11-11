#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n ,a[N] , m ,ans,num[N],d[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool bk = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] != i)bk = 1;
	}
	for(int i=1;i<n;i++) d[i] = a[i+1]-a[i];
	sort(d+1,d+1+n);
	if(bk == 0){
		cout<<min(m+1,n);
	}
	else if(d[1]==d[n]){
		cout<<min(n,m/d[1]+1);
	}
	else{
		sort(a+1,a+1+n); 
		for(int i=1;i<=n;i++) num[i] = num[i-1] + a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int po = a[j] * (j-i+1)-num[j]-num[i-1];
				if(po <= m) ans = max(ans,j-i+1);
			}
		}
		cout<<ans; 
	}
	return 0;
}
