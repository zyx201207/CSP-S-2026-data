#include<bits/stdc++.h>
using namespace std;
long long a[500500];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(m<1e8+5){
		sort(a,a+n);
		for(int i=0;i<n;i++){
			int l=i-1;
			long long m1=m;
			long long ls=1;
			while(l>-1){
				if(a[i]-a[l]<=m1){
					m1-=a[i]-a[l];
					ls++;
					l--;
				}
				else break;
			}
			ans = max(ans,ls);
		}
		cout << ans;
	}
	else{
		int c = a[1]-a[0];
		for(ans = 1;ans<=n;ans++){
			if((ans-1)*c*ans/2>m){
				ans--;
				break;
			}
		}
		cout << ans;
	}
	return 0;
}
