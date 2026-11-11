#include <bits/stdc++.h>
using namespace std;

int nums[500005]{};
bool isaaa = true;

struct Node{
	int val,to = -1;
};

int m1,n;

int main(){	

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	map<int,int> cnt;
	cin >> n >> m1;
	for(int i = 1;i <= n;++i){
		if(nums[i] < nums[i-1])isaaa = false;
		cin >> nums[i];
	}
	if(isaaa){
		vector<int> hash(m1+5);
		for(int i = 1;i <= n;++i){
			hash[nums[i]] = i;
		}
		for(int i = 1;i <= m1;++i)cout << hash[i] << ' ';
	}
	for(int i = 1;i <= n;++i){
		vector<Node> hash(m1+5);
		int l = i;
		int r = i+1;
		hash[nums[l]].val = 1;
		while(r <= n){
			if(hash[nums[r]].val == 1){
				hash[nums[r]].to = r;
			}
			else {
				hash[nums[r]].val = 1;
			}
			++r;
		}
		for(int j = l;j <= n;++j){
			if(hash[nums[j]].to != -1){
				j = hash[nums[j]].to;
			}
			if(cnt.count(nums[j]) == 1){
				++cnt[nums[j]];
			}
			else{
				cnt[nums[j]] = 1;
				
			}
		}
	}
	
	for(int i = 1;i <= m1;++i)cout << cnt[i] << ' ';
	
	return 0;
}
