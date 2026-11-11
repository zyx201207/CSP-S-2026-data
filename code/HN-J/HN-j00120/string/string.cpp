#include<bits/stdc++.h> 
using namespace std;
long long n,a,ans;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+='0';
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	for(int i=1;i<=s.size()/2-1;i++){
		if(s[i]!=s[s.size()-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
