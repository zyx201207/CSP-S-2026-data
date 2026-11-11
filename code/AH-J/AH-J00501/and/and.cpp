#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> path;
int r;
void backtracking(vector<int> &nums,int n,int target,int startIndex){
	if((int)path.size()==target){
		r=max(r,path[0]&path[1]);
		return;
	}
	for(int i=startIndex;i<=n;i++){
		path.push_back(nums[i]);
		backtracking(nums,n,target,i+1);
		path.pop_back();
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> nums(n,0);
	for(int i=0;i<=n;i++){
		cin>>nums[i];
	}
	backtracking(nums,n,m,1);
	cout<<r;
    return 0;
}
