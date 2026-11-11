#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fileIO(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

bool cmp(ll a,ll b){
	return a<b;
}

const int N = 1e6;
ll nums[N];

int main(){
	fileIO("crystal");
	fastIO();

	ll n;
	ll m;
	cin >> n >> m;
	for (int i = 1;i<=n;i++){
		cin >> nums[i];
	}
	if (m>=5000){

		ll ii = 0;
		while(m>=ii){
			m-=ii;
			ii++;
		}
		cout << min(ii,n) << '\n';
		return 0;
	}


	sort(nums+1,nums+n+1,cmp);

	ll maxnum = 0;
	for (int i = 1;i<=n;i++){
		for (int j = i+1;j<=n;j++){
			ll sum = 0;
			for (int k = i;k<=j;k++){
			 	if (nums[k] == nums[k-1]){
			 		sum+=0;
				}
				else{
					sum+=nums[k]-nums[i];
				}
			}
			if (sum<=m){
				maxnum = max(maxnum,(ll)(j-i+1));
			}
		}
	}
	cout << maxnum;

	return 0;
}
