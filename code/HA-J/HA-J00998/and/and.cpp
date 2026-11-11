#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll n,m;
vector<ll> na,nb;
ll b[25] = {0,1};
bool mark111 = false;
ll nums[200001] = {};

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i = 2;i < 21;++i)b[i] = b[i-1]*2;
	
	cin >> n >> m;
	for(int i = 0;i < n;++i){
		ll x;
		cin >> nums[i];
		x = nums[i];
		for(int i = 1;i < 21;++i){
			if(nums[i] != b[i]-1)mark111 = true;
		}
		na.push_back(x);
	}
	
	if(!mark111){
		sort(nums,nums+n,[](int x,int y){return x > y;});
		cout << "11111";
		return 0;
	}
	
	ll res = -1;
	for(int aaa = 1;aaa < m;++aaa){
		for(int i = 0;i < n;++i){
			for(int j = i+1;j < n;++j){
				nb.push_back(na[i]&na[j]);
			}
		}
		na.clear();
		for(int i = 0;i < nb.size();++i){
			na.push_back(nb[i]);
		}
		nb.clear();
	}
	for(int i = 0;i < na.size();++i){
		res = max(res,na[i]);
	}
	cout << res;
	
	return 0;
}
