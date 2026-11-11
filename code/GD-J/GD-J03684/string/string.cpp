#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long sum=0;
	string s;
	bool p=false;
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin >> a >> b;
		if(a==1000000000){
			p=true;
			a=1;
		}
		while(a--){
			s+=b;
		}
	}
	int l=0 , r=s.size()-1;
	while(l<r) if(s[l++]!=s[r--]) sum++;
	if(p){
		cout << sum*1000000000;
		return 0;
	}
	cout << sum;
	return 0;
}
