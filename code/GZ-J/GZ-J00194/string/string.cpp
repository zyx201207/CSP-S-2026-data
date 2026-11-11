//GZ-J00194 遵义市第十九中学 向博熙 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x=0,y=0,c=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		long long a;
		char b;	
		cin>>a>>b;
		x+=a;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	for(int i=1;i<=x-1;i++){
		if(s[i]==s[i-1]){
			y=0;
		}
	}
	for(int i=x-1;i>=0;i--){
		if(s[i]!=s[c]){
			s[i]=s[c];
			y++;
		}
		c++;
	}
	cout<<y;
	return 0;
}
