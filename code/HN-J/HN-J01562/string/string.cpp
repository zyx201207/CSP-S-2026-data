#include<bits/stdc++.h>
using namespace std;
long long q,n,a,t,num;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;++i){
		cin>>a>>c;
		for(int j=t+1;j<=t+a;++j){
			s[j] = c;
		}
		n = n+a,t = t+a;
	}
	for(int i=1;i<=n/2;++i){
		if(s[i]!=s[n-i+1]){
			++num;
		}
	}
	cout<<num;
	return 0;
} 
