#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
	int n;
	cin>>n;
	string s;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	long long cnt=0;
	for(long long i=0; i<s.size()/2; i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
