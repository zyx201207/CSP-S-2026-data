#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,cnt,t;
int a[N];

int check(int x){
	int sum=0;
	for(int i=n; i>=1; i--){
		if(a[i] <= x){
			sum+=x-a[i];
			cnt++;
		}
		if(sum <= m){
			t=cnt;	
		}
	}
	return sum;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	} 
	sort(a+1, a+n+1);
	int l=a[1], r=a[n], ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		cnt=0;
		t=0;
		if(check(mid) <= m){
			ans=max(ans, cnt);
			l=mid+1;
		}else{
			ans=max(ans, t);
			r=mid-1;
		}	
	}
	cout<<ans;
	return 0;
}

