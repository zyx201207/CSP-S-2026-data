#include <bits/stdc++.h> 
using namespace std;
int t;
int n,cnt;
string s1,s;
int ef(string c,long long l,long long r){
	long long mid = (l+r)/2;
	long long cnt = 0;
	if(r%2==0){
		for(long long i = 0; i < mid; i++){
			if(c[i]!=c[r-i-1]){
				cnt++;
			}
		}
	}
	else{
		for(long long i = 0; i < mid; i++){
			if(c[i]!=c[r-i-1]){
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	freopen("sting.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n >> s;
		for(int i = 1; i <= n; i++){
			s1+=s;
		}
	}
	long long len = s1.size();
	cout << ef(s1,0,len);
	return 0;
}
