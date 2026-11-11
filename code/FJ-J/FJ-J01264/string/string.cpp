#include <bits/stdc++.h>
using namespace std;
string t[6000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			t[i]+=c;
		}
	}
	string s,b;
	for(int i=1;i<=n;i++){
		s+=t[i];
	}
	int g=0;
	for(int i=s.size();i>=0;i--){
		b+=s[i];
	}
	for(int j=0;j<s.size();j++){
		if(b[j]==s[j]){
			g++;
		}
	}
	if(g+1==s.size()){
		cout << "0";
	}
	else
	cout << (s.size()-g+1)/2;
	return 0;
}
