#include <bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long cnt = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
    int l = 1,r = n;
    while(l < r){
    	if(b[l] != b[r]){
    		if(a[l] <= a[r]){
    			cnt += a[l];
				a[r] -= a[l];
				a[l] = 0; 
				l++;
				if(a[r] == 0){
					r--;
				}
			}else {
				cnt += a[r];
				a[l] -= a[r];
				a[r] = 0;
				r--;
				if(a[l] == 0){
					l++;
				}
			}
		}else if(b[l] == b[r]) {
			if(a[l] == a[r]){
				a[l] = 0;
				a[r] = 0;
				l++;
				r--;
			}else if(a[l] < a[r]){
				a[r] = a[r] - a[l];
				a[l] = 0;
			}else if (a[r] < a[l]){
				a[l] = a[l] - a[r];
				a[r] = 0;
			}
		}
	}
	cout << cnt; 
	return 0;
}
