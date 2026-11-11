#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>nums;
int maxx=static_cast<int>(-0x3f3f3f3f);
void fun(int i,int j,vector<int>&vec){
	if(j>nums.size()) return;
	if(i==0){
		int result=vec[0];
		for(int t:vec){
			result=result&t;
		}
		maxx=max(maxx,result);
		return;
	}
	for(int k=j;k<nums.size();k++){
		vector<int>t=vec;
		vec.push_back(nums[k]);
		fun(i-1,k+1,vec);
		vec=t;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		int t;cin>>t;
		nums.push_back(t);
	}
	vector<int>a;
	fun(m,0,a);
	cout<<maxx;
	
	
	return 0;
}
