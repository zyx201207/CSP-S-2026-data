#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (long long i = 2;i <= n;i++){
		if (a[i] == a[i-1]) continue;
		long long nw = m,cnt = 0,num = 0;
		for (long long j = i;;j++){
			if (a[j]!=a[i]) break;
			num++;
		}
		for (;nw > 0;){
			if (cnt > i-1) break;
			nw -= a[i]-a[i-1-cnt];
			cnt++;
		}
		if (nw < 0) cnt--;
		ans = max(ans,cnt+num); 
	}
	cout<<ans;
}
