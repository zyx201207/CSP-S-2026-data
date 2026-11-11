#include<bits/stdc++.h>
using namespace std;

vector<long long> v ;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s_ ;
	int n;
	cin >> n;
	long long a;
	for(int i=0; i<n; i++){
		cin >> a >> s;
	} 
	for(int j=2; j<=a; j++){
		s += s_;
		if(a%2 != 0){
		s_ = s_+s;
		}
	}
	if(a == 1){
		s += s_;
	}
	if(s==s){
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
