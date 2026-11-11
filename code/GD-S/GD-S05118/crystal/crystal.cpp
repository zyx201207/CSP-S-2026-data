#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Num{
	int a;
	int cnt;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m;
	cin>>n>>m;
	
	vector<long long> a;
	for(int i=0;i<n;i++){
		long long ai;
		cin>>ai;
		
		a.push_back(ai);
	}
	
	sort(a.begin(),a.end());

	vector<Num> nums;
	int len=0;
	for(int i=0;i<n;i++){
		if(len==0){
			nums.push_back({a[i],1});
			len++;
			continue;
		} 
		
		if(a[i]==nums[len-1].a){
			nums[len-1].cnt++;
		}else{
			nums.push_back({a[i],1});
			len++;
		}
	}
	
	long long step=m;
	for(int i=0;i<len-1;i++){
		if(step<=0){
			break;
		}
		int icnt=nums[i].cnt;
		long long d=nums[i+1].a-nums[i].a;
		
		long long can=step/d;
		
		if(can==0){
			continue;
		}
		
		if(can>=icnt){
			nums[i+1].cnt+=nums[i].cnt;
			step-=nums[i].cnt*d;
			nums[i].cnt=0;
		}else{	
			nums[i+1].cnt+=can;
			nums[i].cnt-=can;
			step-=can*d;
		}
	}
	
	int ans=0;
	for(Num t : nums){
		if(t.cnt>=2){
			ans=max(t.cnt,ans);
		}
	}
	
	cout<<ans;
	return 0;
} 
