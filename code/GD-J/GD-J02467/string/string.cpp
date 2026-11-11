#include<bits/stdc++.h>

using namespace std;

long long a[200005],pre[200005],n;
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	pre[0] = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		pre[i] = pre[i - 1] + a[i];
	}
	long long sum = 0;
	long long k = 1,l = 1,r = n;
	if(pre[n] % 2 == 0){
		while(k <= pre[n]/2){
			long long last_k = k;
			k = min(a[l] + pre[l - 1],pre[n] - pre[r] + a[r]);
			if(c[l] != c[r]){
				sum += 1LL*(k - last_k + 1);
			} 
			k++;
			if(k > a[l] + pre[l - 1]){
				l++;
			}
			if(k > pre[n] - pre[r] + a[r]){
				r--;
			}
		}
	}
	else{
		while(k < (pre[n]+1)/2){
			long long last_k = k;
			k = min(a[l] + pre[l - 1],pre[n] - pre[r] + a[r]);
			if(c[l] != c[r]){
				sum += 1LL*(k - last_k + 1);
			} 
			k++;
			if(k > a[l] + pre[l - 1]){
				l++;
			}
			if(k > pre[n] - pre[r] + a[r]){
				r--;
			}
		}
	}
	cout<<sum;
}
