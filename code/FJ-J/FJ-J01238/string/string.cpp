#include<bits/stdc++.h>
using namespace std;
long long n,a,ans,s1,s2;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		s1+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	s2=s1;
	s1=s1/2;
	for(int i=0;i<s1;i++){
		if(s[i]!=s[s2-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
