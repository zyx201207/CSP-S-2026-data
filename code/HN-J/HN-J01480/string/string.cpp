#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	while(n--){
		int t;
		char c;
		cin>>t>>c;
		for(int i=1;i<=t;i++){
			s+=c;
		}
	}
	int len=s.size();
	for(int i=0;i<=len>>1;i++){
		if(s[i]!=s[len-i-1]) ans++;
	} 
	cout<<ans;
	return 0;
}
