#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1; i<=n; i++) {
		long long a;
		cin>>a;
		char a1;
		cin>>a1;
		for(int j=1; j<=a; j++) {
			s+=a1;
		}
	}
	if(s.size()%2==1){
			cout<<s.size()/2;
		}else{
			cout<<0;
		}
	return 0;
}
