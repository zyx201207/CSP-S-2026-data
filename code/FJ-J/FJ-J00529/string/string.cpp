#include<bits/stdc++.h>
using namespace std;
long long n,i,a,ans=0;
char c;
string s,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(i=1;i<=a;i++){
			s=s+c;
		}
	}
	for(i=s.size()-1;i>=0;i--){
		s2=s2+s[i];
	}
	for(i=s.size()/2;i<s.size();i++){
		if(s[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
