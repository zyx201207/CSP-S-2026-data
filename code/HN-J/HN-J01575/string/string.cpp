#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,b=0;
	char c;
	cin>>n;
	string s="";
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			s[s.size()-i-1]=s[i];
			b++;
		}
	}
	cout<<b;
	return 0;
}
