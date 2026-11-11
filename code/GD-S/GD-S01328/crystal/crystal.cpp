#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin>>n>>m;
    vector<long long> nums(n);
    bool isA=true;
	bool isB=true; 
	int cha=0;
    for (int i=0;i<n;i++) {
        cin>>nums[i];
        if (nums[i] != i+1) isA=false;
        if (i==1) cha=nums[1]-nums[0];
		if (i>1 && nums[i]-nums[i-1]!=cha) isB=false;  
    }
    if (isA) {
    	int sum=0;
		for (int i=2;;i++) {
			sum=sum+i-1;
			if (sum>m) {
				cout<<i-1;
				return 0;
			} else if (sum==m) {
				cout<<i;
				return 0;
			}
		} 
	}
	if (isB) {
    	int sum=0;
		for (int i=1;;i++) {
			sum=sum+(i-1)*cha;
			if (sum>m) {
				cout<<i-1;
				return 0;
			} else if (sum==m) {
				cout<<i;
				return 0;
			}
		} 
	}
    sort(nums.begin(), nums.end());

	int maxn=0;
	for (int i=n-1;i>=0;i--) {
		int sum=0;
		int k=nums[i];
		int l=1;
		while (sum<=m && l<=i) {
			sum+=k-nums[i-l];
			if (sum>m) break;
			l++;
		}
		maxn = max(maxn, l);
	}
	cout<<maxn;
	
    return 0;
}



