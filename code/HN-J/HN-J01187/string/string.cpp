//wu nai moli canna 52pts
#include<bits/stdc++.h>
using namespace std;
int n,b,cnt=0;
string a="",c="";
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b;
		cin>>a;
		for(int j=1;j<=b;j++)c+=a;
		a="";
	}
	for(int i=0;i<c.length()/2;i++){
		if(!(c[i]==c[c.length()-i-1]))ans++;
	}
	cout<<ans;
	return 0;
} 
