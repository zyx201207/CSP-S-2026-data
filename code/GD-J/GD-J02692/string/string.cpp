#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s += c;
		}
	}
	int len = s.size();
	ll ans = 0;
	//cout<<s<<endl; 
	for(int i=0;i<len/2;i++)
	if(s[i]!=s[len-i-1]){
		//cout<<s[i]<<' '<<s[i-1]<<'\n'; 
		ans ++;
	}
	cout<<ans;
	return 0;
} 
