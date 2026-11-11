#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		string p;
		cin >> p;
		for(long long j=0;j<x;j++){
			s+=p;
		}
	}
	int sum=0;
	for(int x=0,y=s.size()-1;x<s.size()/2,y>s.size()-s.size()/2-1;x++,y--){
		if(s[x]!=s[y]){
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
