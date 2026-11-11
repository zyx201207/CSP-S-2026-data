#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n; cin>>n;
	string s; cin>>s;
	for (int i=1;i<=s.size()-1;i++){
		cin>>s;
	}
	int cnt = 0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			if (s[i]!=s[j]){
				cnt++;
			}	
		}
	}
	cout<<cnt;
	return 0;
}