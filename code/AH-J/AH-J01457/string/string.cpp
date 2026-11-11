#include "bits/stdc++.h"
using namespace std;
#define int long long

int n,number[200005];
char w[200005];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>number[i]>>w[i];
	
	int l = 1,r = n,ans = 0;
	while(l < r){
		if(w[l] == w[r]){
			if(number[l] == number[r]){
				l++;
				r--;
			}
			else if(number[l] < number[r]){
				number[r] -= number[l];
				l++;
			}
			else if(number[l] > number[r]){
				number[l] -= number[r];
				r--;
			}
			
		}
		
		else{
			if(number[l] == number[r]){
				ans += number[l];
				l++;
				r--;
			}
			else if(number[l] < number[r]) {
				ans += number[l];
				number[r] -= number[l];
				l++;
			}
			else if(number[l] > number[r]) {
				ans += number[r];
				number[l] -= number[r];
				r--;
			}
			
		}
	}
	cout<<ans<<endl;
	return 0;
}


