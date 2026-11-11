#include<bits/stdc++.h>
using namespace std;
long long n;
string s="";
long long L;
int main(){
	cin>>n;
	long long cnt;
	while(n--){
		long long a;
		string c;
		cin>>a>>c;
		for(long long i=1;i<=a;i++){
			s+=c;
		}
		L+=a;
	}
	for(int i=0;i<L/2;i++){
		if(s[i]!=s[L-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
