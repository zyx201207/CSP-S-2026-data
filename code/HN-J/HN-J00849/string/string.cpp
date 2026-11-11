#include<bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
long long n,arr[maxn],ans,l,r,x;
char s[maxn],y; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>x>>y;
		arr[i] = x;
		s[i] = y;
	}
	l = 1;
	r = n;
	while(l < r){
		if(arr[l] == arr[r]){
			if(s[l] != s[r]){
				ans += arr[l];
			}
			l++;
			r--;
		}
		if(arr[l] < arr[r]){
			if(s[l] != s[r]){
				ans += arr[l];
			}
			arr[r] -= arr[l];
			l++;
		}
		if(arr[l] > arr[r]){
			if(s[l] != s[r]){
				ans += arr[r];
			}
			arr[l] -= arr[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
