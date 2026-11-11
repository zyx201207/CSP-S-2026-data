#include<bits/stdc++.h>

using namespace std;
string s;
int N;
long long cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>N;
	s=" ";
	while(N--){
		int a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	for(long long i=1;i<=long long(s.size()-1)/2+1;i++){
		if(s[i]!=s[long long(s.size()-1)+1-i]){
			cnt++;
		}
	}
	cout<<cnt/2; 
	return 0;
}
