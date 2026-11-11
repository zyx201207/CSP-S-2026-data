#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s;
int n,a,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

