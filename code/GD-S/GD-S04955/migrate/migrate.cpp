#include<bits/stdc++.h>
using namespace std;
//constexpr int maxn = 0; 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t,n,d;
	cin >> c >> t;
	for (int ct = 0;ct<t;ct++){
		cin >> n >> d;
		int nums[n];
		int steps[n];
		int father[n];
		for(int i = 0;i<n;i++){
			cin >> nums[i];
		}
		int st = 0;
		int us = 0;
		int end = 0;
		int j = 0;
		for(int i = 1;j<n;i++){
			st = nums[i] - nums[j];
			us = st/d+1;
			if(2*d-1+i<n){
				steps[i] = 1;
				j++;
				i--;
			}
		}
//		cout << j << endl;
		while(j>=0){
			if(j-d>0){
				steps[j-d] += steps[j];
			}
			else{
				end += steps[j];
			}
			j--;
		}
//		for(int i = 0 ;i<n;i++){
//			cout << father[i] << " ";
//		}
//		cout << endl;
		cout << end << endl;
	}
	return 0;
}
