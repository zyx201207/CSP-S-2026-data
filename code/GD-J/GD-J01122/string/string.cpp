#include <bits/stdc++.h>
using namespace std;
int n,a,cnt=0;
string s="";
string s1;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> s1;
		for(int j=1;j<=a;j++){
			s+=s1;
		}
	}
	int len=s.size();
	bool v=1;
	for(int i=0;i<len-1;i++){
		if(s[i]!=s[len-i-1]){
			v=0;
		}
	}
	if(v){
		cout << 0;
		return 0;
	}
	for(int i=0;i<len-1;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
		}
		if(i==len-i-1){
			break;
		}
	}
	cout << cnt;
	return 0;
}
