#include <bits/stdc++.h>
using namespace std;
long long cnt;


int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	char c;
	string s = "";
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> c;
		s.append(a,c);
	}
	string ss = s;
	reverse(ss.begin(),ss.end());
	if(s == ss){
		cout << 0;
		return 0;
	}
	
	long long l=0,r=s.size()-1;
	while(l<=r){
		if(s[l] == s[r]){
			l++;
			r--;
		}
		else{
			s[l] = s[r];
			l++;
			r--;
			cnt++;
		}
	}
	cout << cnt;
		
	return 0;
}
