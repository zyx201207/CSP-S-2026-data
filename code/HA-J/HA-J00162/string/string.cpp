#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	s+='0';
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	long long l=s.size();
	for(int i=1; i<l; i++){
		if(s[i]!=s[l-i]) ans++;
	}
	cout<<ans/2;
	return 0;
}
