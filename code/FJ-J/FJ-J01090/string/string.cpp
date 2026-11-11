#include<bits/stdc++.h>
using namespace std;
string s,m;
int n,a,b;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(cin>>n;n>0;n--){
		cin>>a>>c;
		for(;a>0;a--) s+=c;
	}int z=s.size()/2;
	for(int i=z;i>=0;i--) m+=s[i];
	for(int i=z;i<=s.size();i++) if(m[i-z]!=s[i]) b++;
	cout<<b<<endl;
	return 0;
}
