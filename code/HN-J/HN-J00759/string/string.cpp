#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
string s;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s += b[i];
		}
	}
	
	for(int i=s.size()-1;i>=s.size()/2+1;i--){
		int c=s.size()-1-i;
		if(s[i] != s[c]){
			s[i] = s[c];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
