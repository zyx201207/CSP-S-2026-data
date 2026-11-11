#include<bits/stdc++.h>

using namespace std;

int n ,m;

vector<long long>nums;
vector<long long>an;
long long ands1 = 0, ands2 = 0, ands3 = 0, ands4 = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		nums.push_back(x);
	}
	sort(nums.begin(),nums.end());
	ands1 = nums[n - 1];
	
	for(int i = 0; i < m;i++){
		ands1 &= nums[n - i - 1];
	}
	
	ands2 = nums[n - 2];
	
	for(int i = 0; i < m;i++){
		ands2 &= nums[n - i - 2];
	}
	
	ands3 = nums[n - 3];
	
	for(int i = 0; i < m;i++){
		ands3 &= nums[n - i - 3];
	}
	
	ands4 = nums[n - 4];
	
	for(int i = 0; i < m;i++){
		ands4 &= nums[n - i - 4];
	}
	
	cout << max( max(ands1, ands2), max(ands3, ands4)) << endl;
	
	return 0;
}
