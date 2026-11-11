#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,ans=0,l=0;
	char c;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
		l+=x;
	}
	
	for(int i=1;i<=l/2;i++){
		if(s[i-1]!=s[l-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}  
