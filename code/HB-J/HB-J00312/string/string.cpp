#include<bits/stdc++.h>
using namespace std;
long long n,len,a,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		for(int i=1;i<=a;i++){
			s=s+c;
		}
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
