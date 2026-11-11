#include<bits/stdc++.h>
using namespace std;
string s;
long long a,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(NULL);
	char c;
	int cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
