#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	string c;
	char e='0';
	c+=e;
	int n,p=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c_;
		cin>>a>>c_;
		for(int j=1;j<=a;j++){
			p++;
			c+=c_;
		}
	}
	for(int i=1;i<=p-i+1;i++){
		if(c[i]!=c[p+1-i]){
			s++;
		}
	}
	cout<<s;
}
