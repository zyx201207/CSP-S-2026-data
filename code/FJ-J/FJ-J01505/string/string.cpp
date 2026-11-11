#include<bits/stdc++.h>
using namespace std;
char s[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long len=0,ans=0;
	cin>>n;
	while(n--){
		long a;
		char c;
		cin>>a>>c;
		if(a>=1000000000){
			ans=(n/2)*a;
			break;
		}
		for(int i=len+1;i<=a+len;i++){
			s[i]=c;
		}
		len+=a;
	}
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len+1-i]){
		s[len+1-i]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
