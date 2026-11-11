#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10; 
int n,m,a[N],s[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	if(m == 1){
		cout << n;
	}else{
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		
		int ans1 = 0,ans2 = 0;
		
		if(a[n - 1] == a[n]){
			if(a[n - 1] == 1){
				cout << n << " 0";
			}else{
				cout << "0 " << n;
			}
			return 0;
		}
		for(int i = 1;i <= n - 1;i++){
			if(a[n - 2] == a[n] && i % 2 == 0){
				if(a[n] == 1){
					ans1++;
				}else{
					ans2++;
				}
			}else{
				if(a[n - 1] == 1){
					ans1++;
				}else{
					ans2++;
				}
				
				if(a[n] == 1){
					ans1++;
				}else{
					ans2++;
				}
			}
				
		}
		if(a[n] == 1){
			ans1++;
		}else{
			ans2++;
		}
		cout << ans1 << " " << ans2; 
	}
		
	return 0;
} 
