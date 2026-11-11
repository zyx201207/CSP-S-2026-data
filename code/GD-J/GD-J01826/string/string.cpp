#include<bits/stdc++.h>
using namespace std;
char ch;
string s;
long long n,num,ans,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>num>>ch;
		for(int i=1;i<=num;++i) s+=ch;
	}
	m=s.size()/2+s.size()%2;
	for(int i=0;i<=m;++i){
		int j=s.size()-i;
		if(s[i]!=s[j]) ++ans;
	}
	cout<<ans;
	return 0;
}
