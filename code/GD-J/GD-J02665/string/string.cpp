#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string ss;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		string s;
		cin>>a>>s;
		for(int i=1;i<=a;i++) ss+=s;
	}
	long long ans=0;
	long long len=ss.length();
    for(int i=0;i<len/2;i++){
    	if(ss[i]!=ss[len-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}  
