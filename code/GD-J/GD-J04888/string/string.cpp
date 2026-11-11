#include <bits/stdc++.h>
using namespace std;

struct Letter{
	long long num;
	char c;
	
	void get_data(){
		cin >> num;
		cin >> c;
	}
}L[200000];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans = 0;
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		L[i].get_data();
	}
	int l = 0,r = n-1;
	while(l <= r){
		n = min(L[l].num,L[r].num);
		if(L[l].c != L[r].c){
			ans += n;
		}
		if(L[l].num == n){
			l++;
		}else{
			L[l].num -= n;
		}
		if(L[r].num == n){
			r--;
		}else{
			L[r].num -= n;
		}
	}
	cout << ans;
	return 0;
}
