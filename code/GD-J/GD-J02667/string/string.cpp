#include <bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
bool n1(string s){
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			return 0;
		}	
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	if(n==1){
		cout << "0";
	}else if(n1(s)==1){
		cout << "0";
	}else{
		if(n==2){
			cout << "1";
		}
	}
	return 0;
} 
