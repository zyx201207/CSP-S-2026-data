#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	string s;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin >> a >> c;
		for(long long j=0;j<a;j++){
			s+=c;
		}
	}
	long long ans=0;
	for(long long i=0;i<(s.size()/2);i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
