#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,ans=0,l=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int u;
		char v;
		cin>>u>>v;
		l+=u;
		for(int j=0;j<u;j++)s+=v;
	}
	for(int i=0;i<l/2;i++){
		ans+=(s[i]!=s[l-i-1]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
