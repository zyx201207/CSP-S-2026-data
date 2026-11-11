#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	while(n--){
		int m;
		string c;
		cin>>m>>c;
		while(m--){
			s+=c;
		}
	}
	long long len=s.size();
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[len-i-1])cnt++;
	}
	cout<<cnt;
}
