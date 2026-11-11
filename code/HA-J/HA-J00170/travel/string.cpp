#include<bits/stdc++.h>
using namespace std;

string s;
int cnt;

int main(){
	freopen("string.in.in","r",stdin);
	freopen("string.out.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		int x;
		string a;
		cin >> x >> a;
		for(int i=1; i<=x; i++){
			s+=a;
		}
	}
	for(int i=1; i<=(s.size()/2); i++){
		if(s[i]!=s[s.size()+1-i]) cnt++;
	}
	cout << cnt;
	return 0;
}
