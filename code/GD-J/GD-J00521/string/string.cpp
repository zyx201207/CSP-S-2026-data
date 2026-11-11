#include <bits/stdc++.h>
using namespace std;
string s=" ";
char c;
long long n,a,sl,sll,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--) s+=c;
	}sl=s.length()/2,sll=s.length()-1;
	for(int i=1;i<=sl;i++){
		if(s[i]!=s[sll-i+1]) ans++; 
	}printf("%lld",ans);
}
