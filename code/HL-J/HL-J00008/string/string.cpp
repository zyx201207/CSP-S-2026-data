#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		char ch;
		cin>>ch;
		for(int j=1;j<=num;j++){
			s+=ch;
			len++;
		}
	}
	
	int ans=0;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
