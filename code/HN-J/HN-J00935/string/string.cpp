#include <bits/stdc++.h>
using namespace std;
int n,a,l,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s[l++]=c;
		}
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
