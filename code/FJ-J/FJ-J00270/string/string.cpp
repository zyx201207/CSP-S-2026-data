#include<bits/stdc++.h>
using namespace std;
long long c[200010];
int d[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long sum = 0;
	for(int k = 1;k <= n;k++){
		int a;
		char b;
		cin >> a >> b;
		c[k] = a;
		sum += a;
		d[k] = b - 'a';
	}
	long long ans = 0;
	int ii = 0,jj = n;
	long long lef = 0,rig = sum;
	while(lef <= rig){
		if(ii == jj){
			break;
		}
		if(d[ii] == d[jj]){
			if(c[ii] >= c[jj]){
				lef += c[jj];
				rig -= c[jj];
				
				c[ii] -= c[jj];
				c[jj] = 0;
				jj--;
			}else{
				lef += c[ii];
				rig -= c[ii];
				
				c[jj] -= c[ii];
				c[ii] = 0;
				ii++;
			}	
		}else{
			if(c[ii] >= c[jj]){
				lef += c[jj];
				rig -= c[jj];
				ans += c[jj];
				c[ii] -= c[jj];
				c[jj] = 0;
				jj--;
			}else{
				ans += c[ii];
				lef -= c[ii];
				rig += c[ii];
				c[jj] -= c[ii];
				c[ii] = 0;
				ii++;
			}
		}
	}
	cout << ans;
	return 0;
} 
