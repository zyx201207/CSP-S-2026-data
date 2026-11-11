#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s; 
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;
		char ch;
		string s3;
		cin >> a >> ch;
		for(int i=1;i<=a;i++){
			s3+=ch;
		}
		s+=s3;
	}
	string s2;
	for(int i=s.size()-1;i>=0;i--){
		s2+=s[i];
	}
	if(s==s2){
		cout << 0;
	}else{
		if(n%2==1){
		    cout << n/2+1;
		}else{
			cout << n/2;
		}
	}
	return 0;
}
