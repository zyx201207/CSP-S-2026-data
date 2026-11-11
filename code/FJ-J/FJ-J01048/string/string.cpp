#include <bits/stdc++.h>
using namespace std;
char c[100000005];
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	s+=" ";
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a>>c[i];
		for(int j=1;j<=a;j++){
			s+=c[i];
		}
	}
	for(int i=1;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
