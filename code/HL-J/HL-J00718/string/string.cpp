#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	string s;
	long long a=0;
	string c;
	for(int i=0;i<n;i++){
		cin >> a >> c;
		while(a>0){
			s+=c;
			a--;
		}
	}
	string t=s;
	reverse(t.begin(),t.end());
	int cnt=0;
	for(int i=0;i<t.size();i++){
		if(t[i]!=s[i]){
			cnt++;
		}
	}
	cout << cnt/2;
	return 0;
}