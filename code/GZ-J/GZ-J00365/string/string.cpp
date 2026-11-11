//GZ-J00365 ºî¶÷Í® 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a;
int n,ans;
char c;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a>>c;
		for(int j = 1;j <= a;j++){
			s+=c;
		}
	}
	for(int i = 0;i < s.length()/2;i++){
		int j = s.length()-i-1;
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
