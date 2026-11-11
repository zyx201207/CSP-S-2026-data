#include<bits/stdc++.h>
using namespace std;
int a[500005] = {};
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
    int mem = 1;
    int ans = 1, m1 = m;
    while (m1){
    	int cha = a[mem+1] - a[mem];
    	if(mem*cha <= m1){
            m1 -= (mem*cha);
            mem++;
            ans++;
        }else{
        	break;
		}
	}
	for(int i = 2; i <= n; i++){
		if(a[i] == a[i-1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
