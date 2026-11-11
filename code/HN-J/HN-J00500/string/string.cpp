#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,ans = 0;
	string s;
	cin>>n;
	for(int i = 0;i<n;i++){
		long long a;
		cin>>a;
		char c;
		cin>>c;
		while(a--){
			s += c;
		}
	}
	int len = s.size();
	for(int i = 0;i<(len-1)/2+1;i++){
		if(s[i] != s[len-i-1]){
			s[len-i-1] = s[i];
			ans++;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
