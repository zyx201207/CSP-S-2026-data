#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,x;
char a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>x>>a;
		for(int j=1;j<=x;j++) {
			s+=a;
		}
	}
	int len=s.size(),ans=0;
	s=' '+s;
	for(int i=1;i<=len/2;i++) {
		if(s[i]!=s[len+1-i]){
			ans++;
		}
	}
	cout<<ans;
}

