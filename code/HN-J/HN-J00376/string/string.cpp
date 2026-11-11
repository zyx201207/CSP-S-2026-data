#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,m = 0;
	string s = "",a;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x >> a;
		m += x;
		for(int j = 1;j <= x;j++){
			s += a;
		}
	}
	int ans = 0; 
	if(m % 2 == 0){
		string s1 = s.substr(0,m/2);
		string s2 = s.substr(m/2,m/2);
		string s3 = "";
		for(int i = m/2-1;i >= 0;i--){
			s3 += s2[i];
		}
		for(int i = 0;i < m/2;i++){
			if(s1[i] != s3[i])
				ans++;
		} 
		cout << ans;
	}
	else{
		string s1 = s.substr(0,m/2);
		string s2 = s.substr(m/2+1,m/2);
		string s3 = "";
		for(int i = m/2-1;i >= 0;i--){
			s3 += s2[i];
		}
		for(int i = 0;i < (m-1)/2;i++){
			if(s1[i] != s3[i])
				ans++;
		}
		cout << ans;
	}
}
