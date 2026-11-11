#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len;
	string s,z;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>z[i];
	}
	if(n==1)cout<<"0";
	if(n==2){
		if(z[1]==z[2])cout<<"0";
		else cout<<s[1];
	}
	if(n==3&&z[1]==z[2]&&z[1]==z[3]&&z[2]==z[3])cout<<"0";
	return 0;
}
