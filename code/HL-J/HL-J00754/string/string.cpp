#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l = 0;cin >> n;
	string s = "";
	for(int i = 0;i < n;i++){
		int x;char ss;cin >> x >> ss;
		while(x--){
			s += ss;
			l++;
		}
	}
	int cnt = 0;
	string si = s;
	reverse(s.begin(),s.end());
	string f;
	for(int i = s.size()/2;i < s.size();i++){
		if(si == f){
			break;
		}
		if(s[i] != si[i]){
			si[i] = s[i];
			cnt++;
		}
		f = si;
		reverse(f.begin(),f.end());
	}
	cout << cnt;
	return 0;           	
}