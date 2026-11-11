#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
string s;
int l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	l=s.size();
	for(int i=0;i<=l/2-1;i++){
		if(s[i]!=s[l-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
