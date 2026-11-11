#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long len=s.length();
	bool flag=1;
	long long ans=0;
	if(len%2==1){
		for(int i=0;i<((len-1)/2);i++){
			if(s[i]!=s[len-1-i]){
				flag=0;
				ans++;	
			}
		}
	}
	else{
		for(int i=0;i<len/2;i++){
			if(s[i]!=s[len-1-i]){
				flag=0;
				ans++;	
			}
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
