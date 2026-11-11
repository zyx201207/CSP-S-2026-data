#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long nn;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s=" ";
	for(int i=1;i<=n;i++){
		int ni;
		char c;
		cin>>ni>>c;
		nn+=ni;
		while(ni--)s+=c; 
	}
	for(int l=1,r=nn;l<=r;l++,r--){
		ans+=(s[l]!=s[r]);
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
