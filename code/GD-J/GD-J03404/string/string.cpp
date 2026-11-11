//csp RP++
#include<bits/stdc++.h>
using namespace std;
string s;
char c;
long long n,cnt=0,a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		} 
	}
	cout<<cnt;
	return 0;
}
