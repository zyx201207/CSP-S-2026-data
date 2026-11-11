#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	long long len = s.size()-1,cnt = 0;
	for(long long i=0,j=len;i<j;i++,j--){
		if(s[i] == s[j]){
			continue;
		}
		else{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;	
}