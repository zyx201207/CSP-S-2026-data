//GZ-S00261 贵阳市第三十三中学 叶发睿 
#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e6+10;
int n, m, a[N], cnt = 0;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	
	while(m--){
		int l = 1, r = n;
		for(int i = 1; i <= n; i++){
			int mid = (r+l)/2;
			r = mid-1;
			if(a[i]!=mid){
				a[i]++;
				break;
			}
			else{
				cnt++;
				i++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
