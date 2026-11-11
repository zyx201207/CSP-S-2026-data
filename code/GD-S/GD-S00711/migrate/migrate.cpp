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

const int N = 1e6;
int nums[N];

int main(){
	fileIO("migrate");
	fastIO();
	int c,t;
	cin >> c >> t;
	for (int i = 0;i<t;i++){
		int n,d;
		cin >> n >> d;
		for (int j = 0;j<n;j++){
			cin >> nums[j];
		}
		int ans = 0;
		for (int j = 0;j<n;j++){
			for (int k = j+1;k<n;k++){
				if ((d<nums[k]-nums[j] && nums[k]-nums[j]<2*d)){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	
	
	
	
	return 0;
}
