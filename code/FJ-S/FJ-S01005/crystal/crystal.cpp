#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,l=0,r=0,dqcs=0,ans=1;
	cin >> n >> m;
	for(long long i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	while(r<n-1){
		r++;
		dqcs += (a[r]-a[r-1])*(r-l);
		if(dqcs>m){
			while(dqcs>m){
				l++;
				dqcs -= a[r]-a[l-1];
			}
		}
		ans = max(ans,r-l+1);
	}
	cout << ans;
	return 0;
}
