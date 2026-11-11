#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
char c;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	bool f=true;
	for(int l=0;l<=s.size()/2;l++){
		if(s[l]!=s[s.size()-l-1]){
		   f=false;
		}
	}
	if(f==true){
		cout<<"0";
	}
	else{
		for(int l=0;l<=s.size()/2;l++){
			if(s[l]!=s[s.size()-l]){
			   ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
