#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long chazhi[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool isA = true,isB = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i){
			isA = false; 
		}
	}
	for(int i = 1;i < n;i++){
		chazhi[i] = a[i + 1] - a[i];
	}
	for(int i = 1;i < n - 1;i++){
		if(chazhi[i] != chazhi[i + 1]){
			isB = false;
		}
	}
	if(isA){
		isB = false;
	}
	sort(a + 1,a + n + 1);
	if(isA){
		long long ans = (-1 + sqrt(1 + 8 * m)) / 2;
		cout << ans + 1;
	}else{
		int ans = 0;
		long long cnt = 0;
		for(int i = n;i >= 1;i--){
			bool ischanged = false;
			cnt = 0;
			for(int j = i - 1;j >= 1;j--){
				if(a[i] - a[j] + cnt > m){
					ans = max(ans,i - j);
					ischanged = true;
					break;
				}
				cnt += (a[i] - a[j]);	
			}	
			if(!ischanged){
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
