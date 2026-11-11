#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n;
long long ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=0;
	for(int i=1;i<=n;i++){
		int num;
		char s1;
		cin>>num>>s1;
		for(int j=1;j<=num;j++){
			s+=s1;
		}
		l+=num;
	}
	s=' '+s;
	for(int i=1;i<=(l/2);i++){
		if(s[i]!=s[l-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
