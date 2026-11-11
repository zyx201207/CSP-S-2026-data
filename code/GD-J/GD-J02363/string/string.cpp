#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char a[n+10];
	string s = "";
	long long sum = 0;
	bool flag = true;
	for(int i = n ; i > 0 ; i--){
		long long x;
		cin>>x;
		sum+=x;
		cin>>a[n-i];
		if(a[n-1] != a[n-i-1] && i != n) flag = false;//是否全为同一数 
		for(int j = 1 ; j <= x ; j++){
			s += a[n-i];
		}
	}
	long long len = s.size();
	long long ans = 0;
	if(flag){
		cout<<0;
		return 0;
	}else{
		if(sum % 2){
			for(int i = 0 ; i < (len+1)/2 ; i++){
				if(s[i] != s[len-i-1]){
					ans++;
				}
			}
		}else{
			for(int j = 0 ; j < len/2 ; j++){
				if(s[j] != s[len-j-1]){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
