//GZ-J00515 邹俊杰 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,x;
string s;
char a;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a;	
		for(int j=1;j<=x;j++){
			s=s+a;
		}
	}
	for(int i=1;i<=s.size()/2+1;i++){
		if(s[i]!=s[s.size()-i+1])ans++;
	}
	cout<<ans;
	return 0;
} 
