#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,m,nums[maxn];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		cin >> nums[i];
	int maxm = -0x7f7f7f7f;
	if(m == 2){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++)
				if(nums[i] && nums[j] > maxm)
					maxm = nums[i] && nums[j]; 
		}
	}
	cout << maxm;
	return 0;
} 
