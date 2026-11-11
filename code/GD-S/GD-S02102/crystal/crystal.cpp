#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 7;
ll a[N],s[N],n,m;

bool check(int p,int cnt){
	return a[p] * cnt - (s[p-1] - s[p-cnt-1]) <= m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0); 
	int _ = 1;//cin >> _;
	while(_--){
		cin >> n >> m;
		for(int i=1;i<=n;i++)cin >> a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)s[i] = s[i-1] + a[i];
		int ans = 0;
		for(int i=1;i<=n;i++){
			int l = 0,r = i-1;int res = 0;
			while(l <= r){
				int mid = (l + r)/2;
				if(check(i,mid))res = mid,l = mid+1;
				else r = mid - 1;
			}
			ans = max(ans,res+1);
			//cout << res << "\n";
		} 
		cout << ans;
	}
	return 0;
}

//Code by mid27_(luogu),welcome to follow me,
//I will RP++++++++++++++++++++++++++++++++,use liu xu huan's 10 life to let me this code can get full scores!!!!! 

