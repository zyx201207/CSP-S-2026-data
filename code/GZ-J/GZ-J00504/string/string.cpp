//中央民族大学附属中学贵阳学校 夏宇森 GZ-J00504
#include<bits/stdc++.h>
using namespace std;
const int N = 2e6;
int n;
unsigned long long sum=0;
vector<int> nums;
vector<char> cha;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		nums.push_back(x);
		char ch; cin >> ch;
		cha.push_back(ch);
	}
	int l = 0, r = n-1; sum = 0;
	while(l < r){
		if(l==r){
			break;
		} 
		if(cha[l] != cha[r]){
			sum += min(nums[l], nums[r]);
		}
		if(nums[l]>nums[r]){
			nums[l] -= nums[r];
			r--;
		}
		else if(nums[l]<nums[r]){
			nums[r] -= nums[l];
			l++;
		}
		else{
			l++; r--;
		}
	}
	cout << sum;
	return 0;
}
