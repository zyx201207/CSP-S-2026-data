#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	scanf("%lld", &n);
	string s = "";
	long long sum=0;
	while(n--){
		long long a;
		scanf("%lld", &a);
		sum += a;
		string s1;
		cin >> s1;
		while(a--){
			s+=s1;
		}
	}
	long long ans=0;		

	if(sum%2 != 0){
	    long long mid = sum/2+1;
	    long long l = mid-1, r = mid+1;
		while(l-1 >= 0 && r-1 <= s.size()){
			if(s[l-1] != s[r-1]) ans++;
			l--;
		    r++;
		}	
	}else{
		long long mid = sum/2;
		long long l = mid-1, r= mid+1;
		while(l >= 0 && r-1 <= s.size()){
			if(s[l] != s[r-1]) ans++;
			l--;
		    r++;
		}	
	}
	printf("%lld", ans);
	return 0;
}
