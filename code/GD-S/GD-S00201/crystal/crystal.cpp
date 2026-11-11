#include <bits/stdc++.h>
using namespace std;

const int MAXn = 5e5+5;

long long n,m,ans=0;
long long a[MAXn],b[MAXn],c[MAXn];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) b[i] = a[i]-a[i-1];
	long long l=1,r=1,cnt=0;
	while (r <= n){
		cnt += b[r]*(r-l);
		while(cnt > m){
			cnt -= a[r]-a[l];
			l++;
		}
		r++;
		ans = max(ans,r-l);
		//cout<<l<<" "<<r<<" "<<cnt<<endl;
	}
	
	cout<<ans;
	
	
	
	return 0;
} 

/*

in1
5 5
1 2 4 8 9

in2
5 8
-3 -1 2 2 7

*/


