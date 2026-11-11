#include<bits/stdc++.h>
using namespace std;
unsigned long long n,len=0,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		len+=a;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=0;i<=(len-1)/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
	    }
	}
	cout<<ans;
	return 0;
}
