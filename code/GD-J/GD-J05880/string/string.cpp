#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for(int i=1;i<=n;i++){
		int t;
		char a;
		cin >> t >> a;
		while(t--){
			s+=a;
		}
	}
	string s1=s;
	reverse(s1.begin(),s1.end());
	long long cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=s1[i]){
			cnt++;
		}
	}
	cout << cnt/2;
	return 0;
}
