#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x=1,l=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		l+=a;
		for(int i=x;i<=x+a;i++){
			s[i]=c;
		}x+=a+1;
	}for(int i=1;i*2+1<=l;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}cout<<ans;
	return 0;
}
