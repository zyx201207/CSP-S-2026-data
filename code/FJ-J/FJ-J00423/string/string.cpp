#include <bits/stdc++.h>
using namespace std;
long long n,a,len,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=len;j<len+a;j++){
			s[j]=c;
		}
		len+=a;
	}
	for(int i=len-1;i>=len/2+1;i--){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
