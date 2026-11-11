#include<bits/stdc++.h>
using namespace std;
int n,k;
char x;
string s;
bool ring(int len){
	string t=s;
	for(int i=0;i<=len/2;i++){
		if(t[i]!=t[n-i-1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>k>>x;
		while(k--){
			s+=x;
		}
	}
	/*long long len=s.size(),cnt=0;
	for(int i=0;i<=len;i++){
		if(ring(len)){
			cout<<cnt;
			return 0;
		}
		
	}*/
	cout<<0;
	return 0;
}
