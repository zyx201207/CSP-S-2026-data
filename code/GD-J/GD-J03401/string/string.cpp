#include<bits/stdc++.h>
using namespace std;
int n;
long long a,ans;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(n==1){
			cout<<0;
			return 0;
		}
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int len=s.size();
	for(int i=0;i<=len/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
