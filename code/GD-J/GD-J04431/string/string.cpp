#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;

	for(int i = 0; i<n; i++){
		cin>>a[i]>>c[i];
	}
	long long left1 = 0;
	long long right1 = n-1;
	long long ans = 0;
	
	while(left1 <= right1){

		if(a[left1] > a[right1]){
			if(c[left1] != c[right1]){
				ans += a[right1];
			}
			a[left1] -= a[right1];
			right1 --;
		}
		else if(a[left1] == a[right1]){
			if(c[left1] != c[right1]){
				ans += a[right1];
			}
			right1 --;
			left1 ++;
		}
		else{
			if(c[left1] != c[right1]){
				ans += a[left1];
			}
			a[right1] -= a[left1];
			left1 ++;
		}
		
	}
	cout<<ans;
	return 0;
}
