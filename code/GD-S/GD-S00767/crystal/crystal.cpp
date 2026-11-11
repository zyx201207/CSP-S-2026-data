#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m; 
	cin >> n >> m;
	vector<int> a(n+1),sum(n+1,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		sum[i] = (a[i]-a[i-1])*(i-1) + sum[i-1];
	}
	deque<int> dq;
	int ans = 1;
	
	int i=1,j=1;
	for(;i<=n;i++){
		while(j<i and sum[i]-sum[j]-(a[i]-a[j])*(j-1) > m) j++;
		int tans = i - j + 1;
		ans = max(ans,tans);
	}
	
//	for(int i=1;i<=n;i++){
//		if(!dq.empty()){
//			while(!dq.empty() and sum[i]-sum[dq.back()]-(a[i]-a[dq.back()])*(i-1) > m) dq.pop_back();
//		} 
//		dq.push_front(i);
//		ans = max(ans,dq.size());
//	}
	
	cout << ans << '\n';
	
	return 0;
}
