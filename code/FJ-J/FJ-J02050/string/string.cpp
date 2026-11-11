#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	s="";
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		while(a--)s=a+c;
	}
	int ans=0;
	for(int i=0;i<s.length();i++){
		if(s[i]!=s[s.length()-1-i])ans++;
	}
	cout<<ans/2;
	return 0;
}
