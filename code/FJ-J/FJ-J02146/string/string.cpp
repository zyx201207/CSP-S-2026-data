#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	int m;
	cin>>m;
	string n;
	for(int i=0;i<m;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int i=0;i<a;i++){
			n.push_back(b);
		}
	}
	int cnt=0;
	for(int i=0;i<floor(n.size()/2.0);i++){
		if(n[i]!=n[n.size()-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
}
