#include<bits/stdc++.h>
using namespace std;
int n;
string s,x;
int number;
int ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;+
	while(n--){
		cin>>number>>x;
		for(int i=1;i<=number;i++){
			s+=x;
		}
	}
	//cout<<s;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]) ans++;
		else continue;
		//cout<<s[i]<<' '<<s[s.size()-1-i]<<endl;
	}
	cout<<ans;
	return 0;
}
