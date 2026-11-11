#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char b[200005];
string s,s2;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>b[i];
	for(int j=1;j<=a[i];j++){
		s+=b[i];
	}
}
for(int i=s.size()-1;i>=0;i--){
	s2[i]=s[i];
}
for(int i=0;i<s.size();i++){
	
}
    return 0; 
} 
